#include "./lib/arr.c"

List switchNumsXor(List nums) {
  unsigned a = nums.arr[0];
  unsigned b = nums.arr[1];

  a = a ^ b;
  b = b ^ a;
  a = a ^ b;

  List switchedNums = {2, malloc(2)};
  switchedNums.arr[0] = a;
  switchedNums.arr[1] = b;

  return switchedNums;
}

List switchNumsMod(List nums) {
  unsigned a = nums.arr[0];
  unsigned b = nums.arr[1];

  // Switch with a*(a+b-1) mod (a+b)
  // This works because in the field F_(a+b) numbers will wrap around.
  unsigned newA = a * (a + b - 1) % (a + b);
  unsigned newB = b * (a + b - 1) % (a + b);

  List switchedNums = {2, malloc(2)};
  switchedNums.arr[0] = newA;
  switchedNums.arr[1] = newB;

  return switchedNums;
}

List switchNumsSimple(List nums) {
    unsigned a = nums.arr[0];
    unsigned b = nums.arr[1];

    a = a + b;
    b = a - b;
    a = a - b;

    List switchedNums = {2, malloc(2)};
    switchedNums.arr[0] = a;
    switchedNums.arr[1] = b;

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

  List nums = {2, malloc(2)};
  nums.arr[0] = a;
  nums.arr[1] = b;

  printf("Switching with mod: ");
  List switchedNumsMod = switchNumsMod(nums);
  arr_print(&switchedNumsMod);

  printf("Switching with XOR: ");
  List switchedNumsXor = switchNumsXor(nums);
  arr_print(&switchedNumsXor);

  printf("Switching with + and -: ");
  List switchedNumsSimple = switchNumsSimple(nums);
  arr_print(&switchedNumsSimple);

  return 0;
}
