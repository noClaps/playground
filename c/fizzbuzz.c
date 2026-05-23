#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void fizzbuzz(int64_t n) {
  for (int64_t i = 1; i <= n; i++) {
    if (i % 3 == 0) {
      printf("Fizz");
    }
    if (i % 5 == 0) {
      printf("Buzz");
    }
    if (i % 3 != 0 && i % 5 != 0) {
      printf("%lld", i);
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {
  int64_t n = atoll(argv[1]);
  fizzbuzz(n);
}
