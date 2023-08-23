import CryptoKit
import Foundation

print("Enter a length of password")
while true {
  if let input = readLine(), let length = Int(input), length >= 1 {
    if generatePassword(length: length) == "" {
      print("Choose a shorter length of password")
    } else {
      print("Your password: \(generatePassword(length: length))")
      print("Make sure to keep it safe in a password manager!")
      
      break
    }
  } else {
    print("That's not a valid number")
  }
}

func generatePassword(length: Int) -> String {
  var string = ""

  for _ in 1...getRandom(reps: length) {
    let now = Date().timeIntervalSinceReferenceDate
    let inputData = Data(String(now).utf8)
    let hashed = SHA512.hash(data: inputData)
    string = hashed.description
  }

  if string.count < length {
    return ""
  }

  let start = string.index(string.startIndex, offsetBy: 15)
  let end = string.index(string.startIndex, offsetBy: 15 + length - 1)
  let range = start...end
  let newString = String(string[range])

  return newString.separate(every: 5, with: " ")
}

func getRandom(reps: Int) -> Int {
  return Int.random(in: 1...reps)
}

extension String {
  func separate(every stride: Int = 4, with separator: Character = " ") -> String {
    return String(
      enumerated().map { $0 > 0 && $0 % stride == 0 ? [separator, $1] : [$1] }.joined())
  }
}
