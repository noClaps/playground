#include "lib.h"

unsigned *switchNumsXor(unsigned *nums) {
  unsigned a = nums[0];
  unsigned b = nums[1];

  a = a ^ b;
  b = b ^ a;
  a = a ^ b;

  unsigned *switchedNums = malloc(2);
  switchedNums[0] = a;
  switchedNums[1] = b;

  return switchedNums;
}

unsigned *switchNumsMod(unsigned *nums) {
  unsigned a = nums[0];
  unsigned b = nums[1];

  // Switch with a*(a+b-1) mod (a+b)
  // This works because in the field F_(a+b) numbers will wrap around.
  unsigned newA = a * (a + b - 1) % (a + b);
  unsigned newB = b * (a + b - 1) % (a + b);

  unsigned *switchedNums = malloc(2);
  switchedNums[0] = newA;
  switchedNums[1] = newB;

  return switchedNums;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr,
            "Too few arguments. Correct usage is ./switch <number> <number>");
    exit(1);
  }

  unsigned a = strtoul(argv[1], NULL, 10);
  unsigned b = strtoul(argv[2], NULL, 10);

  unsigned *nums;
  nums[0] = a;
  nums[1] = b;

  printf("Switching with mod: ");
  arr_print(switchNumsMod(nums), 2);

  printf("Switching with XOR: ");
  arr_print(switchNumsXor(nums), 2);

  return 0;
}
