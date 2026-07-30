// You start at the beginning of an array (index=0). The value of the array at
// that index is the jump distance. Determine if you can reach the end of the
// array.

#include <stdio.h>

typedef struct {
  size_t len;
  int *values;
} IntArray;

int main() {
  IntArray my_array = {.len = 5, .values = (int[]){2, 3, 1, 1, 4}};

  size_t i = 0;
  while (1) {
    i += my_array.values[i];
    if (i > my_array.len || my_array.values[i] == 0) {
      printf("false\n");
      break;
    } else if (i == my_array.len - 1) {
      printf("true\n");
      break;
    }
  }
}
