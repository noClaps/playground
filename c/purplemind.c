#include <stdio.h>
#include <stdlib.h>

double problem() {
  double x = arc4random() / (double)UINT32_MAX;

  while (x != 0 && x != 1) {
    double coin = arc4random() / (double)UINT32_MAX;
    if (1 - x > x) {
      // closer to 0
      if (coin < 0.5) {
        // left
        x = 0;
      } else {
        // right
        x = x + x;
      }
    } else {
      // closer to 1
      if (coin < 0.5) {
        // left
        x = x - (1 - x);
      } else {
        // right
        x = 1;
      }
    }
  }

  return x;
}

int main() {
  const uint64_t ATTEMPTS = 100000;
  uint64_t num0 = 0, num1 = 0;

  for (uint64_t i = 1; i <= ATTEMPTS; i++) {
    if (problem() == 0) {
      num0 = num0 + 1;
    } else {
      num1 = num1 + 1;
    }
  }
  printf("0: %llu\n1: %llu\n", num0, num1);
}
