import Foundation

func factorise(n: Int) -> Int {
  var n = n
  var quotient = 3

  while quotient <= n {
    if n % quotient == 0 {
      n /= quotient
    } else {
      quotient += 2
    }
  }
  return quotient
}

print("Largest factor of 13195: \(factorise(n: 13195))")
print("Largest factor of 600851475143: \(factorise(n: 600_851_475_143))")
