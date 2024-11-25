#pragma once

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_in_range(unsigned long long num, char *firstArg) {
  char *numStr;
  asprintf(&numStr, "%llu", num);

  if (num == 0 || strncmp(numStr, firstArg, 21) > 0) {
    fprintf(stderr, "Input too small, the minimum input is 1.\n");
    exit(2);
  } else if (strncmp(numStr, firstArg, 21) < 0) {
    fprintf(stderr,
            "Input too large, the maximum input is 18446744073709551615.\n");
    exit(2);
  }

  free(numStr);
}

/*
This function finds the maximum value of two inputs.
*/
unsigned long long max(unsigned long long a, unsigned long long b) {
  if (a > b)
    return a;
  return b;
}

/*
This function prints an array with nice formatting, like in other languages
like TypeScript, Python, or Swift.
*/
void arr_print(unsigned long long *arr, size_t arr_size) {
  if (arr_size == 0) {
    printf("[]\n");
    return;
  }

  printf("[");
  for (size_t i = 0; i < arr_size - 1; i++)
    printf("%llu, ", arr[i]);

  printf("%llu]\n", arr[arr_size - 1]);
}
