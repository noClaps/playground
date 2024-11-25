#include "lib.h"
#include <math.h>
#include <stdlib.h>

struct tuple {
  unsigned long long *arr;
  size_t len;
};

/*
This function takes a number to factorise, and an existing list of factors. The
list of factors is needed as this function is recursive and that is the only
way I could think of to keep track of the factors. The initial factors array
when calling this function from `main()` should be created using `malloc()` and
should not contain any values. The only reason this is necessary is because C
doesn't support default arguments.
*/
struct tuple factorise(unsigned long long num, unsigned long long *factors,
                       size_t arr_size) {
  unsigned long long originalNum = num;

  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      num /= i;
      arr_size = arr_append(factors, arr_size, i);
      break;
    }
  }

  if (num == originalNum) {
    arr_size = arr_append(factors, arr_size, num);
  } else {
    struct tuple f = factorise(num, factors, arr_size);
    factors = f.arr;
    arr_size = f.len;
  }

  struct tuple f = {factors, arr_size};
  return f;
}

/*
To run this program, you need to pass in the number you're trying to factorise
as the first argument. It will then return an array of
numbers that are the prime factors of that number. Example:

`$ ./pf 25`
`[5, 5]`

The maximum input is 18446744073709551615.
*/
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Incorrect usage. Correct usage is ./pf <number>\n");
    exit(1);
  }

  char *eptr;
  unsigned long long num = strtoull(argv[1], &eptr, 10);
  check_in_range(num, argv[1]);

  unsigned long long *factorsArr = malloc(0);

  struct tuple f = factorise(num, factorsArr, 0);
  arr_print(f.arr, f.len);

  return 0;
}
