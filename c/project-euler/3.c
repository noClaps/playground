#include <stdio.h>

long largestPrimeFactor(long number) {
  int divisor = 3;

  while (divisor <= number) {
    if (number % divisor == 0) {
      number /= divisor;
    } else {
      divisor += 2;
    }
  }

  return divisor;
}

int main() {
  printf("%ld\n", largestPrimeFactor(600851475143));
  return 0;
}