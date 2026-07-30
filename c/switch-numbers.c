#include <stdio.h>
#include <stdlib.h>

void switch_nums_mod(int *a, int *b) {
  // Switch with a*(a+b-1) mod (a+b)
  // This works because in the field F_(a+b) numbers will wrap around.
  int new_a = *a * (*a + *b - 1) % (*a + *b);
  int new_b = *b * (*a + *b - 1) % (*a + *b);

  *a = new_a;
  *b = new_b;
}

void switch_nums_xor(int *a, int *b) {
  int new_a = *a;
  int new_b = *b;

  new_a = new_a ^ new_b;
  new_b = new_b ^ new_a;
  new_a = new_a ^ new_b;

  *a = new_a;
  *b = new_b;
}

void switch_nums_simple(int *a, int *b) {
  int new_a = *a;
  int new_b = *b;

  new_a = new_a + new_b;
  new_b = new_a - new_b;
  new_a = new_a - new_b;

  *a = new_a;
  *b = new_b;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Not enough parameters\n");
    return 1;
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  switch_nums_mod(&a, &b);
  printf("Switching with mod: %d %d\n", a, b);

  a = atoi(argv[1]);
  b = atoi(argv[2]);
  switch_nums_xor(&a, &b);
  printf("Switching with XOR: %d %d\n", a, b);

  a = atoi(argv[1]);
  b = atoi(argv[2]);
  switch_nums_simple(&a, &b);
  printf("Switching with + and -: %d %d\n", a, b);

  return 0;
}
