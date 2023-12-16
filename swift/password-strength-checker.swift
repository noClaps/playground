import Foundation

func charSet(password: String) -> Int {
  var totalCharSet = 0

  if password.contains(try! Regex("[A-Z]")) {
    print("✓ Has uppercase")
    totalCharSet += 26
  } else {
    print("✕ does not have uppercase")
  }

  if password.contains(try! Regex("[a-z]")) {
    print("✓ Has lowercase")
    totalCharSet += 26
  } else {
    print("✕ does not have lowercase")
  }

  if password.contains(try! Regex("[0-9]")) {
    print("✓ Has numbers")
    totalCharSet += 10
  } else {
    print("✕ does not have numbers")
  }

  if password.contains(try! Regex("[^A-Za-z0-9]")) {
    print("✓ Has special characters")
    totalCharSet += 33
  } else {
    print("✕ does not have special characters")
  }

  return totalCharSet
}

func rating(entropy: Double) -> String {
  if entropy < 20 { return "Very weak" }
  if entropy < 40 { return "Weak" }
  if entropy < 60 { return "Okay" }
  if entropy < 80 { return "Strong" }
  return "Very strong"
}

print("\nWelcome to the noClaps password strength checker\n")

print("Input your password:")
let passwd = readLine() ?? ""
let totalCharSet = charSet(password: passwd)

let entropy = log2(pow(Double(totalCharSet), Double(passwd.count)))
let pwdRating = rating(entropy: entropy)

print("Password entropy: \(entropy) ")
print("Password rating: \(pwdRating)\n")
