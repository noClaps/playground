import Foundation

struct Args {
    var help: Bool
    var isInt: Bool
    var coin: Bool
    var min: Double
    var max: Double

    mutating func parse() {
        var remainingArgs: [String] = []
        let argv = CommandLine.arguments

        for i in 1..<Int(CommandLine.argc) {
            if !argv[i].starts(with: "-") {
                remainingArgs.append(argv[i])
                continue
            }
            switch argv[i] {
            case "--help", "-h": help = true
            case "-i": isInt = true
            case "-c", "--coin": coin = true
            default: continue
            }
        }

        if remainingArgs.count == 1 {
            max = Double(remainingArgs[0])!
        } else if remainingArgs.count == 2 {
            min = Double(remainingArgs[0])!
            max = Double(remainingArgs[1])!
        }
    }
}

var args = Args(help: false, isInt: false, coin: false, min: 0, max: 1)
args.parse()

if args.help {
    print(
        """
        USAGE: \(CommandLine.arguments[0]) [-i] [--coin] [<min>] [<max>]

        ARGUMENTS:
          <min>          The minimum value for the random number generator. (default: 0.0)
          <max>          The maximum value for the random number generator. (default: 1.0)

        OPTIONS:
          -i             Should the output be an integer?
          -c, --coin     Flip a coin instead of generating a number.
          -h, --help     Show help information.
        """)
    exit(0)
}

if args.coin {
    if Int.random(in: 0...1) == 0 {
        print("Heads")
    } else {
        print("Tails")
    }
    exit(0)
}

if args.min > args.max {
    print("ERROR: Min value is larger than max value (\(args.min) > \(args.max))")
    exit(1)
}

if args.isInt {
    print(Int.random(in: Int(args.min)...Int(args.max)))
} else {
    print(Double.random(in: args.min...args.max))
}
