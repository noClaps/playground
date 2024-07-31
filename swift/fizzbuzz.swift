for i in 1...10000 {
    switch (i%3, i%5) {
        case (0, 0): print("Fizzbuzz")
        case (0, _): print("Fizz")
        case (_, 0): print("Buzz")
        default: print(i)
    }
}
