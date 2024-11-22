#include <_string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

size_t max(size_t a, size_t b) {
  if (a > b)
    return a;
  return b;
}

/*
This function calculates the size of an array. It assumes that the array was
initialised with malloc() and that all empty elements are 0.
*/
size_t arr_size(unsigned long long *arr) {
  size_t size;
  for (size = 0; arr[size] != 0; size++)
    ;
  return size;
}

/*
This function prints an array with nice formatting, like in other languages
like TypeScript, Python, or Swift. It uses the `arr_size()` function to find
the length of the array, so any empty elements in the array should be 0.
*/
void arr_print(unsigned long long *arr) {
  size_t arrLen = arr_size(arr);

  printf("[");
  for (size_t i = 0; i < arrLen - 1; i++)
    printf("%llu, ", arr[i]);

  printf("%llu]\n", arr[arrLen - 1]);
}

/*
This function takes a number to factorise, and an existing list of factors. The
list of factors is needed as this function is recursive and that is the only
way I could think of to keep track of the factors. The initial factors array
when calling this function from `main()` should be created using `malloc()` and
should not contain any values. The only reason this is necessary is because C
doesn't support default arguments.
*/
unsigned long long *factorise(unsigned long long num,
                              unsigned long long *factors) {
  unsigned long long originalNum = num;

  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      num /= i;
      factors[arr_size(factors)] = i;
      break;
    }
  }

  if (num == originalNum)
    factors[arr_size(factors)] = num;
  else
    factors = factorise(num, factors);

  return factors;
}

/*
To run this program, you need to pass in the number you're trying to factorise
as the first argument. It will then return an array of
numbers that are the prime factors of that number. Example:

`$ ./pf 25`
`[5, 5]`

The maximum input is 18446744073709551615, any inputs larger than that will
default to 18446744073709551615.
*/
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Incorrect usage. Correct usage is ./pf <number>\n");
    exit(1);
  }

  char *eptr;
  unsigned long long num = strtoull(argv[1], &eptr, 10);

  char *numStr;
  snprintf(numStr, 21, "%llu", num);

  if (!num || strncmp(numStr, argv[1], 21) > 0) {
    fprintf(stderr, "Input too small, the minimum input is 1.\n");
    exit(2);
  } else if (strncmp(numStr, argv[1], 21) < 0) {
    fprintf(stderr,
            "Input too large, the maximum input is 18446744073709551615.\n");
    exit(2);
  }

  size_t arrLen = strnlen(argv[1], num);
  unsigned long long *factorsArr = malloc(max(arrLen, 10));

  arr_print(factorise(num, factorsArr));

  return 0;
}
