#pragma once

#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_in_range(unsigned num, char *firstArg) {
  char *numStr;
  asprintf(&numStr, "%u", num);

  if (strncmp(numStr, firstArg, 11) > 0) {
    fprintf(stderr, "Input too small, the minimum input is 1.\n");
    exit(2);
  } else if (strncmp(numStr, firstArg, 11) < 0) {

    fprintf(stderr,
            "Input too large, the maximum input is %u.\n", UINT_MAX);
    exit(2);
  }

  free(numStr);
}

/*
This function appends a value to the end of an array, and returns the new size.
*/
size_t arr_append(unsigned *arr, size_t arr_size,
                  unsigned elem) {
  arr_size++;
  arr = (unsigned *)realloc(arr, arr_size);
  arr[arr_size - 1] = elem;

  return arr_size;
}

/*
This function prints an array with nice formatting, like in other languages
like TypeScript, Python, or Swift.
*/
void arr_print(unsigned *arr, size_t arr_size) {
  if (arr_size == 0) {
    printf("[]\n");
    return;
  }

  printf("[");
  for (size_t i = 0; i < arr_size - 1; i++)
    printf("%u, ", arr[i]);

  printf("%u]\n", arr[arr_size - 1]);
}
