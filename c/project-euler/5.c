#include <math.h>
#include <stdio.h>

int smallestCommonMultiple(int max) {
  int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
  int product = 1;

  int length = 0;
  while (primes[length] < max) {
    length++;
  }

  for (int i = 0; i < length; i++) {
    product *= pow(primes[i], floor(log(max) / log(primes[i])));
  }

  return product;
}

int main() {
  printf("%d\n", smallestCommonMultiple(20));
  return 0;
}