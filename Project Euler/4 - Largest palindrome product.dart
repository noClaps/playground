// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.

void main() {
  List palindromes = [];

  for (int a = 999; a >= 100; a--) {
    for (int b = 999; b >= 100; b--) {
      int x = a * b;
      String y = x.toString();
      if (y == y.split('').reversed.join('')) {
        palindromes.add(x);
      }
    }
  }

  palindromes.sort();
  print(palindromes[palindromes.length - 1]);
}

// Credits to Qingyang Liu for the solution
