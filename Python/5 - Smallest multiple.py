# 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
# What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

rng = 20

def prodOfList(rng):
    product = 1
    for num in range(2, rng+1):
        product *= num

    return product

def divisibilityTester(rng: int, testVal: int):
    results = []
    for num in range(2, rng+1):
        if testVal % num == 0:
            results.append(True)
        else:
            results.append(False)

    if False not in results:
        return testVal

for i in range(2, prodOfList(rng)//rng):
    if divisibilityTester(rng, i) != None:
        ans = divisibilityTester(rng, i)
        break

print(ans)
