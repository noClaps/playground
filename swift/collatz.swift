func collatzLength(_ n: Int) -> [Int] {
    var nums = [n]
    var n = n

    while n != 1 {
        if n % 2 == 0 {
            n /= 2
        } else {
            n = 3 * n + 1
        }
        nums.append(n)
    }

    return nums
}

let num = Int(CommandLine.arguments[1])!
print(collatzLength(num))
