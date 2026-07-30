#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  size_t len;
  int *values;
} IntArray;

IntArray IntArray_new() {
  int *values = calloc(1, sizeof(int));
  return (IntArray){.len = 0, .values = values};
}

void IntArray_free(IntArray *self) { free(self->values); }

void IntArray_append(IntArray *self, int val) {
  self->values = realloc(self->values, (self->len + 1) * sizeof(int));
  self->values[self->len] = val;
  self->len++;
}

void IntArray_concat(IntArray *self, IntArray other) {
  for (size_t i = 0; i < other.len; i++) {
    IntArray_append(self, other.values[i]);
  }
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

IntArray factorise(int n) {
  if (n < 2) {
    return IntArray_new();
  }

  IntArray factors = IntArray_new();
  int num = n;

  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      num /= i;
      IntArray_append(&factors, i);
      break;
    }
  }

  if (num == n) {
    IntArray_append(&factors, num);
  } else {
    IntArray f = factorise(num);
    IntArray_concat(&factors, f);
    IntArray_free(&f);
  }

  return factors;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <int>\n", argv[0]);
    return 0;
  }
  int n = atoi(argv[1]);
  printf("%s\n", IntArray_fmt(factorise(n)));
}
