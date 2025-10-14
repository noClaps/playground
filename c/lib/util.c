#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void check_in_range(unsigned num, char *firstArg) {
  char *numStr;
  asprintf(&numStr, "%u", num);

  if (strncmp(numStr, firstArg, 11) > 0) {
    fprintf(stderr, "Input too small, the minimum input is 1.\n");
    exit(2);
  } else if (strncmp(numStr, firstArg, 11) < 0) {
    fprintf(stderr, "Input too large, the maximum input is %u.\n", UINT_MAX);
    exit(2);
  }

  free(numStr);
}
