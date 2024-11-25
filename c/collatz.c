#include "lib.h"

struct tuple {
  unsigned *arr;
  size_t size;
};

struct tuple collatz(unsigned num) {
  size_t arr_size = 1;
  unsigned *nums = malloc(arr_size);
  nums[0] = num;

  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
      arr_size = arr_append(nums, arr_size, num);
    } else {
      num = num * 3 + 1;
      arr_size = arr_append(nums, arr_size, num);
    }
  }

  struct tuple t = {nums, arr_size};
  return t;
}

/*
To run this program, you need to pass in the initial value as the first
argument. It will then return an array of all the values after this, until the
output reaches 1. Example:

```
./col 5
```

```
[5, 16, 8, 4, 2, 1]
```

The maximum value is 4294967295.
*/
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Incorrect usage. Correct usage is: ./col <number>\n");
    exit(1);
  }

  unsigned long long num = strtoull(argv[1], NULL, 10);
  check_in_range(num, argv[1]);

  struct tuple t = collatz(num);
  arr_print(t.arr, t.size);

  return 0;
}
