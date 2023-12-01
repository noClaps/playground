for i in 1...10000 {
    if (i % 15 == 0) {
        print("FizzBuzz")
        continue
    }

    if (i % 3 == 0) {
        print("Fizz")
        continue
    }

    if (i % 5 == 0) {
        print("Buzz")
        continue
    }

    print(i)
}
