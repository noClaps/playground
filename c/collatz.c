#include "./lib/arr.c"
#include "./lib/util.c"

List collatz(unsigned num) {
  List nums = {1, malloc(1)};
  nums.arr[0] = num;

  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
      arr_append(&nums, num);
    } else {
      num = num * 3 + 1;
      arr_append(&nums, num);
    }
  }

  return nums;
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

  unsigned num = strtoul(argv[1], NULL, 10);
  check_in_range(num, argv[1]);

  List nums = collatz(num);
  arr_print(&nums);

  return 0;
}
