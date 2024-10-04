// https://www.youtube.com/watch?v=aVUUbNbQkbQ

import Foundation

// Array of fractions being added
var fractions: [String] = []

print("Enter a fraction: ")
let fraction = (readLine(strippingNewline: true) ?? "").split(separator: "/")

// Split fraction into numerator and denominator
var numerator = Int(fraction[0]) ?? 1
var denominator = Int(fraction[1]) ?? 1

if numerator >= denominator {
	print("Improper fraction entered, please try again.")
}

if numerator == 1 {
	fractions.append("1/\(denominator)")
}

while numerator != 1 {
	// Find n such that 1/n < numerator/denominator
	let n = Int(ceil(Double(denominator) / Double(numerator)))
	fractions.append("1/\(n)")

	// numerator/denominator - 1/n
	numerator = numerator * n - denominator
	denominator = denominator * n

	if numerator == 1 {
		fractions.append("1/\(denominator)")
	}

	if numerator == 0 {
		break
	}
}

print(fractions.joined(separator: " + "))
