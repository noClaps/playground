def evenfib(n):
    x = 1
    y = 2
    total = 0
    while x <= n:
        if x % 2 == 0:
            total += x
        z = x + y
        x = y
        y = z

    print(total)

evenfib(4000000)