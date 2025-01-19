// https://www.youtube.com/watch?v=w6xl0IWrZYc

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

double problem() {
  double x = (double)arc4random() / UINT_MAX;

  while (x != 0 && x != 1) {
    if (1 - x > x) {
      // Closer to 0
      double coin = (double)arc4random() / UINT_MAX;
      if (coin < 0.5) {
        // Left
        x = 0;
      } else {
        // Right
        x += x;
      }
    } else {
      // Closer to 1
      double coin = (double)arc4random() / UINT_MAX;
      if (coin < 0.5) {
        // Left
        x -= 1 - x;
      } else {
        // Right
        x = 1;
      }
    }
  }

  return x;
}

int main() {
  int num0 = 0;
  int num1 = 0;

  int ATTEMPTS = 100000;

  for (int i = 0; i < ATTEMPTS; i++) {
    if (problem() == 0) {
      num0++;
    } else {
      num1++;
    }
  }

  printf("0: %d\n1: %d\n", num0, num1);
}
