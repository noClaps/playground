# The prime factors of 13195 are 5, 7, 13 and 29.
# What is the largest prime factor of the number 600851475143 ?

def factorise(n):
    factors = []
    for i in range(2, n+1):
        if n == 1:
            break
        else:
            while n % i == 0:
                for x in factors:
                    if i % x == 0:
                        next
                n //= i
                factors.append(i)

    return factors

print(max(factorise(600851475143)))
