def sumOfMultiples(rng):
    total = 0
    for i in range(rng):
        if i % 3 == 0 or i % 5 == 0:
            total += i

    print(total)


sumOfMultiples(1000)