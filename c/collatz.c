#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  size_t len;
  int *values;
} IntArray;

IntArray IntArray_new() {
  return (IntArray){.len = 0, .values = calloc(1, sizeof(int))};
}

void IntArray_free(IntArray *self) { free(self->values); }

void IntArray_append(IntArray *self, int val) {
  self->values = realloc(self->values, (self->len + 1) * sizeof(int));
  self->values[self->len] = val;
  self->len++;
}

char *IntArray_fmt(IntArray self) {
  if (self.len == 0) {
    return "[]";
  }

  char *out = "";
  asprintf(&out, "[%d", self.values[0]);
  for (size_t i = 1; i < self.len; i++) {
    char *temp = "";
    asprintf(&temp, ", %d", self.values[i]);
    out = realloc(out, strlen(out) + strlen(temp) + 1);
    strlcat(out, temp, strlen(out) + strlen(temp) + 1);
  }
  out = realloc(out, strlen(out) + 2);
  strlcat(out, "]", strlen(out) + 2);
  return out;
}

IntArray collatz_length(int n) {
  IntArray nums = IntArray_new();
  if (n < 1) {
    return nums;
  }
  IntArray_append(&nums, n);

  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
    IntArray_append(&nums, n);
  }

  return nums;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <int>\n", argv[0]);
    return 0;
  }

  int num = atoi(argv[1]);
  IntArray nums = collatz_length(num);
  printf("%s\n", IntArray_fmt(nums));
  printf("length: %lu\n", nums.len);
}
