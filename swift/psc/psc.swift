import Foundation

func charset(_ password: String) -> Int {
    var totalCharset = 0

    // uppercase
    var hasUpper = false
    for c in password {
        if c.isUppercase {
            hasUpper = true
            break
        }
    }
    if hasUpper {
        print("✓ Has uppercase")
        totalCharset += 26
    } else {
        print("✕ does not have uppercase")
    }

    // lowercase
    var hasLower = false
    for c in password {
        if c.isLowercase {
            hasLower = true
            break
        }
    }
    if hasLower {
        print("✓ Has lowercase")
        totalCharset += 26
    } else {
        print("✕ does not have lowercase")
    }

    // numbers
    var hasNumber = false
    for c in password {
        if c.isNumber {
            hasNumber = true
            break
        }
    }
    if hasNumber {
        print("✓ Has numbers")
        totalCharset += 10
    } else {
        print("✕ does not have numbers")
    }

    // special characters
    var hasSpecial = false
    for c in password {
        if !c.isLetter && !c.isNumber {
            hasSpecial = true
            break
        }
    }
    if hasSpecial {
        print("✓ Has special characters")
        totalCharset += 33
    } else {
        print("✕ does not have special characters")
    }

    return totalCharset
}

func rating(_ entropy: Double) -> String {
    return switch entropy {
    case ..<20: "Very weak"
    case ..<40: "Weak"
    case ..<60: "Okay"
    case ..<80: "Strong"
    default: "Very strong"
    }
}

if CommandLine.arguments.contains("--help") || CommandLine.arguments.contains("-h") {
    print(
        """
        USAGE: \(CommandLine.arguments[0]) <password>

        ARGUMENTS:
          <password>    The password to check the strength of.

        OPTIONS:
          -h, --help    Show help information.
        """)
    exit(0)
}

let password = CommandLine.arguments[1]

let totalCharset = charset(password)
let entropy = log2(pow(Double(totalCharset), Double(password.count)))
let pwdRating = rating(entropy)

print(
    """
    Password entropy: \(entropy)
    Password rating: \(pwdRating)
    """)
