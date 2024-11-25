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
This function concatenates two arrays, and frees the memory of the second one.
The parameters are:
- arr1: The array to get concatenated to
- arr1_size: The size of arr1
- arr2: The array getting concatenatated and then freed.
- arr2_size: The size of arr2

It returns the new size of arr1, which is arr1_size + arr2_size.
*/
size_t arr_concat(unsigned *arr1, size_t arr1_size, unsigned* arr2, size_t arr2_size) {
    size_t newSize = arr1_size + arr2_size;
    arr1 = (unsigned*)realloc(arr1, newSize);

    for (size_t i = arr1_size; i < newSize; i++) {
        size_t arr2_index = i - arr1_size;
        arr1[i] = arr2[arr2_index];
    }

    free(arr2);

    return newSize;
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
