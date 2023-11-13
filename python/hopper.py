# You start at the beginning of an array (index=0). The value of the array at
# that index is the jump distance. Determine if you can reach the end of the
# array.

myArray: list[int] = [2, 3, 1, 1, 4]
i: int = 0

while True:
    i += myArray[i]

    if i > len(myArray) or myArray[i] == 0:
        print(False)
        break
    elif i == len(myArray)-1:
        print(True)
        break
