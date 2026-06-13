#include <math.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t *fib_normal(int n) {
  uint64_t *nums = calloc(n, sizeof(uint64_t));

  uint64_t a = 0;
  uint64_t b = 1;

  for (int i = 0; i < n; i++) {
    nums[i] = a;
    uint64_t temp = a + b;
    a = b;
    b = temp;
  }

  return nums;
}

// This is a fast implentation of the Fibonacci sequence that uses repeated
// multiplication with the golden ratio to achieve higher performance.
uint64_t *fib_fast(int n) {
  uint64_t *nums = calloc(n, sizeof(uint64_t));
  if (n == 0) {
    return nums;
  }
  nums[0] = 0;
  if (n == 1) {
    return nums;
  }
  nums[1] = 1;
  if (n == 2) {
    return nums;
  }
  nums[2] = 1;

  const double PHI = (1 + sqrt(5)) / 2;

  for (int i = 3; i < n; i++) {
    nums[i] = round(nums[i - 1] * PHI);
  }

  return nums;
}

uint64_t *fib_binet(int n) {
  uint64_t *nums = calloc(n, sizeof(uint64_t));

  const double PHI = (1 + sqrt(5)) / 2;
  for (int i = 0; i < n; i++) {
    nums[i] = (pow(PHI, i) - pow(-PHI, -i)) / sqrt(5);
  }

  return nums;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <count>\n"
           "Missing required argument: <count>\n",
           argv[0]);
    exit(1);
  }

  int n = atoi(argv[1]);

  uint64_t *fib = fib_normal(n);
  printf("fib normal: [");
  if (n != 0) {
    printf("%llu", fib[0]);
  }
  for (int i = 1; i < n; i++) {
    printf(", %llu", fib[i]);
  }
  printf("]\n\n");

  fib = fib_fast(n);
  printf("fib fast:   [");
  if (n != 0) {
    printf("%llu", fib[0]);
  }
  for (int i = 1; i < n; i++) {
    printf(", %llu", fib[i]);
  }
  printf("]\n\n");

  fib = fib_binet(n);
  printf("fib binet:  [");
  if (n != 0) {
    printf("%llu", fib[0]);
  }
  for (int i = 1; i < n; i++) {
    printf(", %llu", fib[i]);
  }
  printf("]\n\n");

  printf("max uint64_t: %llu\n", UINT64_MAX);
}
