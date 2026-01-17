import Foundation

func fib(_ n: Int) -> [Int] {
    var nums: [Int] = []

    var a = 0
    var b = 1

    for _ in 0..<n {
        nums.append(a)
        (a, b) = (b, a + b)
    }

    return nums
}

/// This is a fast implentation of the Fibonacci sequence that uses repeated
/// multiplication with the golden ratio to achieve higher performance.
func fib2(_ n: Int) -> [Int] {
    switch n {
    case 0: return []
    case 1: return [0]
    case 2: return [0, 1]
    default: break
    }

    var nums = [0, 1, 1]
    let PHI = (1 + sqrt(5)) / 2

    for _ in 2..<n - 1 {
        nums.append(Int(round(Double(nums.last!) * PHI)))
    }

    return nums
}

let n = Int(CommandLine.arguments[1])!

print("fib:", fib(n))
print("fib2:", fib2(n))
