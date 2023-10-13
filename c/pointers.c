#include <stdio.h>

int main(void) {
  int *ptr, number = 10;

  printf("%p\n", &number);
  printf("%p\n", ptr);

  ptr = &number;

  printf("%d\n", number);
  printf("%p\n", ptr);

  *ptr += 20;

  printf("%d\n", number);
  printf("%p\n", ptr);

  return 0;
}