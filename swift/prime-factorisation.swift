import Foundation

func factorise(_ n: Int) -> [Int] {
    if n < 2 {
        return []
    }

    var factors: [Int] = []
    var num = n

    for i in 2...Int(sqrt(Double(n))) {
        if n % i == 0 {
            num /= i
            factors.append(i)
            break
        }
    }

    if num == n {
        factors.append(num)
    } else {
        let f = factorise(num)
        factors += f
    }

    return factors
}

guard let n = Int(CommandLine.arguments[1]) else {
    fatalError("Could not parse integer from argument")
}
print(factorise(n))
