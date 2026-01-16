func fizzbuzz(_ n: Int) {
    for i in 1...n {
        switch (i % 3, i % 5) {
        case (0, 0): print("Fizzbuzz")
        case (0, _): print("Fizz")
        case (_, 0): print("Buzz")
        default: print(i)
        }
    }

}

guard let n = Int(CommandLine.arguments[1]) else {
    fatalError("Could not parse integer from argument")
}
fizzbuzz(n)
