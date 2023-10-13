func fibSum(lim: Int) -> Int {
  var a = 1
  var b = 2
  var sum = 0

  while b < lim {
    let c = a + b
    a = b
    b = c

    if a % 2 == 0 {
      sum += a
    }
  }

  return sum
}

let sumTo100 = fibSum(lim: 100)
print("Sum to 100: \(sumTo100)")

let sumTo4Mil = fibSum(lim: 4_000_000)
print("Sum to 4 million: \(sumTo4Mil)")
