#include <stdio.h>

int sum3Or5(int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }

  return sum;
}

int main() {
  printf("%d\n", sum3Or5(1000));
  return 0;
}