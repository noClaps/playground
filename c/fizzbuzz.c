#include <stdio.h>
#include <stdlib.h>

void fizzbuzz(long n) {
  for (long i = 1; i <= n; i++) {
    if (i % 3 == 0) {
      printf("Fizz");
    }
    if (i % 5 == 0) {
      printf("Buzz");
    }
    if (i % 3 != 0 && i % 5 != 0) {
      printf("%ld", i);
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {
  long n = atol(argv[1]);
  fizzbuzz(n);
}
