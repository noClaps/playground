#include <stdio.h>
#include <stdlib.h>

typedef struct {
  size_t size;
  unsigned *arr;
} List;

void arr_free(List *arr) {
  free(arr->arr);
  arr->arr = NULL;
  arr->size = 0;
}

/*
This function concatenates two arrays, and frees the memory of the second one.
The parameters are:
- arr1: The list to get concatenated to
- arr2: The list getting concatenatated.
*/
void arr_concat(List *arr1, List *arr2) {
  size_t oldSize = arr1->size;
  arr1->size += arr2->size;
  arr1->arr = (unsigned *)realloc(arr1->arr, arr1->size * sizeof(arr1->arr[0]));

  for (size_t i = oldSize; i < arr1->size; i++) {
    size_t arr2_index = i - oldSize;
    arr1->arr[i] = arr2->arr[arr2_index];
  }

  arr_free(arr2);
}

/*
This function appends a value to the end of an array.
*/
void arr_append(List *arr, unsigned elem) {
  arr->size++;
  arr->arr = (unsigned *)realloc(arr->arr, arr->size * sizeof(elem));
  arr->arr[arr->size - 1] = elem;
}

/*
This function prints an array with nice formatting, like in other languages
like TypeScript, Python, or Swift.
*/
void arr_print(List *arr) {
  if (arr->size == 0) {
    printf("[]\n");
    return;
  }

  printf("[");
  for (size_t i = 0; i < arr->size - 1; i++)
    printf("%u, ", arr->arr[i]);

  printf("%u]\n", arr->arr[arr->size - 1]);
}
