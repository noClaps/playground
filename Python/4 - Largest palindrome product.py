# A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
# Find the largest palindrome made from the product of two 3-digit numbers.

palindromes = []
for a in range(999, 100, -1):
    for b in range(999, 100, -1):
        x = a*b
        if str(x) == str(x)[::-1]:
            palindromes.append(x)

print(max(palindromes))

# Credits to Qingyang Liu for the solution
