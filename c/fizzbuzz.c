#include <stdio.h>

int main() {
  for (int i = 1; i <= 1e4; i++) {
    if (i % 15 == 0) {
      printf("%s\n", "FizzBuzz");
      continue;
    }

    if (i % 3 == 0) {
      printf("%s\n", "Fizz");
      continue;
    }

    if (i % 5 == 0) {
      printf("%s\n", "Buzz");
      continue;
    }

    printf("%d\n", i);
  }

  return 0;
}
