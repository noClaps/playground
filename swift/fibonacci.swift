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

let n = Int(CommandLine.arguments[1])!
print(fib(n))
