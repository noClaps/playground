#include "lib.h"
#include <stdlib.h>

/*
This function takes a number and an array, and outputs that number of values in
the Fibonacci sequence.
*/
unsigned *fibonacci(unsigned n) {
  unsigned *nums = malloc(n);

  unsigned a = 0;
  unsigned b = 1;

  for (size_t i = 0; i < n; i++) {
    nums[i] = a;
    unsigned temp = a;
    a = b;
    b += temp;
  }

  return nums;
}

/*
To run this program, you need to pass in the number of Fibonacci sequence
values you want as the first argument. It will then return an array of that
many values in the Fibonacci sequence. Example:

`$ ./fib 5`
`[0, 1, 1, 2, 3]`

The maximum input is 18446744073709551615.
*/
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Incorrect usage. Correct usage is ./fib <number>\n");
    exit(1);
  }

  char *eptr;
  unsigned num = strtoull(argv[1], &eptr, 10);
  check_in_range(num, argv[1]);

  arr_print(fibonacci(num), num);

  return 0;
}
