import CryptoKit
import Foundation

extension String {
    subscript(_ i: Int) -> Character {
        get {
            return Array(self)[i]
        }
        set(newValue) {
            var arr = Array(self)
            arr[i] = newValue
            self = String(arr)
        }
    }

    mutating func replaceAtIndex(_ i: Int, _ char: Character) {
        self[i] = char
    }
}
extension Character {
    func toggleCase() -> Self {
        if isLowercase {
            return Character(uppercased())
        }
        return Character(lowercased())
    }
}

func generatePassword(_ length: Int, _ separator: String) -> String {
    var password = ""

    for i in 0..<length {
        if separator != "" && length > 6 && i % 6 == 0 && i != length {
            password += separator
            continue
        }

        let randInt = Int.random(in: 0..<length)
        let now = Int(Date().timeIntervalSince1970) * randInt

        let hash = SHA3_512.hash(data: "\(now)".data(using: .unicode)!).description
        let hashText = String(hash.suffix(128))

        let randIndex = Int.random(in: 0..<hashText.count)
        password += String(hashText[randIndex])
    }

    for _ in password {
        let randIndex = Int.random(in: 0..<max(password.count - 1, 1))
        password.replaceAtIndex(randIndex, password[randIndex].toggleCase())
    }

    return password
}

struct Args {
    var help = false
    var separator = "-"
    var length = 0

    mutating func parse() {
        var remainingArgs: [String] = []
        let argv = CommandLine.arguments
        var skip = false

        for i in 1..<Int(CommandLine.argc) {
            if skip {
                skip = false
                continue
            }
            if argv[i] == "--help" || argv[i] == "-h" {
                help = true
                continue
            }
            if argv[i] == "-s" {
                separator = argv[i + 1]
                skip = true
                continue
            }
            if !argv[i].starts(with: "-") {
                remainingArgs.append(argv[i])
            }
        }

        if remainingArgs.count > 0 {
            length = Int(remainingArgs[0])!
        }
    }
}

var args = Args()
args.parse()

if args.help {
    print(
        """
        USAGE: \(CommandLine.arguments[0]) <length> [-s <separator>]

        ARGUMENTS:
          <length>      The length of the password to generate.

        OPTIONS:
          -s            The separator for blocks in the password (default: -)
          -h, --help    Show help information.
        """)
    exit(0)
}

let password = generatePassword(args.length, args.separator)
print(password)
