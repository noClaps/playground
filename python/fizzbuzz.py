def fizzBuzz():
        myArray = [i for i in range(1, 10001)]

        for i in range(2, 10000, 3): myArray[i] = "Fizz"
        for i in range(4, 10000, 5): myArray[i] = "Buzz"
        for i in range(14, 10000, 15): myArray[i] = "FizzBuzz"

        print(myArray)

fizzBuzz()
