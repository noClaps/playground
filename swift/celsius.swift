import Foundation

let FREEZING_PT = 32.0
let SCALE_FACTOR = 5.0 / 9.0

print("Enter Fahrenheit temperature: ", terminator: "")

guard let input = readLine() else {
    print("No input found")
    exit(-1)
}

guard let fahrenheit = Double(input) else {
    print("Invalid input: not a number")
    exit(-1)
}

let celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR
print("Celsius equivalent: \(String(format: "%.1f", celsius))")
