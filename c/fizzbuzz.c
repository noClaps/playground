#include "lib.h"

void fizzbuzz(unsigned count) {
    for (unsigned i = 1; i <= count; i++) {
      if (i % 3 && i % 5) {
        printf("%u\n", i);
        continue;
      }

      char string[9] = "";
      if (!(i % 3)) {
        strlcat(string, "Fizz", 5);
      }
      if (!(i % 5)) {
        strlcat(string, "Buzz", 9);
      }
      printf("%s\n", string);
    }
}

/*
To run this program, you have to pass in the maximum number until which to run
FizzBuzz. It will then print each value of FizzBuzz until that maximum, one on
each line. Example

```
./fb 5
```

```
1
2
Fizz
4
Buzz
```

The maximum input is 4294967295.
*/
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Incorrect usage. Correct usage is: ./fb <number>\n");
    exit(1);
  }

  char *eptr;
  unsigned count = strtoull(argv[1], &eptr, 10);

  check_in_range(count, argv[1]);

  fizzbuzz(count);

  return 0;
}
