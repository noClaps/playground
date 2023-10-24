#include <stdio.h>

int fibonacciEvenSum(int max) {
  int sum = 0;
  int a = 1;
  int b = 2;

  while (a < max) {
    if (a % 2 == 0) {
      sum += a;
    }

    int temp = a;
    a = b;
    b = temp + a;
  }

  return sum;
}

int main() {
  printf("%d\n", fibonacciEvenSum(4e6));
  return 0;
}