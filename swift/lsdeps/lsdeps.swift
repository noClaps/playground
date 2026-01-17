import Foundation

struct NPMPackage: Decodable {
    let dependencies: [String: String]?
    let optionalDependencies: [String: String]?
    let peerDependencies: [String: String]?

    init(_ name: String) async throws {
        let url = URL(string: "https://registry.npmjs.org/\(name)/latest")!
        let (data, _) = try await URLSession.shared.data(from: url)
        let decoded = try JSONDecoder().decode(Self.self, from: data)
        self = decoded
    }
}

struct Args {
    var help = false
    var skipOpt = false
    var skipPeer = false
    var name = ""

    mutating func parse() {
        var remainingArgs: [String] = []
        let argv = CommandLine.arguments

        for i in 1..<Int(CommandLine.argc) {
            switch argv[i] {
            case "--help", "-h": help = true
            case "--skip-optional", "-o": skipOpt = true
            case "--skip-peer", "-p": skipPeer = true
            default: break
            }

            if !argv[i].hasPrefix("-") {
                remainingArgs.append(argv[i])
            }
        }

        if remainingArgs.count > 0 {
            name = remainingArgs[0]
        }
    }
}

var args = Args()
args.parse()

if args.help {
    print(
        """
        USAGE: lsdeps <name> [--skip-optional] [--skip-peer]

        ARGUMENTS:
          <name>                 The name of the package to fetch

        OPTIONS:
          -o, --skip-optional    Skip counting optional dependencies.
          -p, --skip-peer        Skip counting peer dependencies.
          -h, --help             Show help information.
        """)
    exit(0)
}

var toFetch = [args.name]
var deps: [String] = []

while toFetch.count > 0 {
    let name = toFetch[0]
    toFetch = Array(toFetch[1...])

    print("Fetching \(name)...")
    let pkg = try await NPMPackage(name)
    var pkgDeps: [String] = []

    if let deps = pkg.dependencies?.keys {
        pkgDeps += deps
    }
    if !args.skipOpt, let deps = pkg.optionalDependencies?.keys {
        pkgDeps += deps
    }
    if !args.skipPeer, let deps = pkg.peerDependencies?.keys {
        pkgDeps += deps
    }

    for dep in pkgDeps {
        if deps.contains(dep) { continue }
        deps.append(dep)
        toFetch.append(dep)
    }
}

print(
    """
    Name: \(args.name)
    URL: https://npmjs.com/package/\(args.name)
    Dependency count: \(deps.count)
    """)
