#include <math.h>
#include <stdio.h>
int sumOfSquares(int n) {
  int sum = 0;

  for (int i = 1; i <= n; i++) {
    sum += pow(i, 2);
  }

  return sum;
}

int squareOfSum(int n) {
  int sum = 0;

  for (int i = 1; i <= n; i++) {
    sum += i;
  }

  return pow(sum, 2);
}

int main() {
  printf("%d\n", squareOfSum(100) - sumOfSquares(100));
  return 0;
}