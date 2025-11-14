#include <stdio.h>
#include <stdlib.h>

#define ITERATIONS 1000

double quadratic_c(double cm1, int count) {
  if (count == 0) {
    return cm1 / 2;
  }
  return cm1 / (2 + quadratic_c(cm1, count - 1));
}

double quadratic_bc(double b, double c, int count) {
  if (count == 0) {
    return b;
  }
  return b + c / (quadratic_bc(b, c, count - 1));
}

double quadratic(double a, double b, double c) {
  if (a == 0) {
    return b / c;
  }
  if (a != 1) {
    b = b / a;
    c = c / a;
  }
  if (b == 0) {
    c = -c;
    // x^2 = c
    // x^2 - 1 = c - 1
    // (x+1)(x-1) = c-1
    // x-1 = (c-1)/(x+1)
    // x = 1 + (c-1)/(2+x)
    double cm1 = c - 1;
    return 1 + quadratic_c(cm1, ITERATIONS);
  }

  // x^2 = bx + c
  b = -b;
  c = -c;
  // x = b + c/x
  //   = b + c/(b + c/x)...
  return quadratic_bc(b, c, ITERATIONS);
}

int main(int argc, char **argv) {
  double a = strtod(argv[1], argv);
  double b = strtod(argv[2], argv);
  double c = strtod(argv[3], argv);
  printf("a = %f, b = %f, c = %f\n", a, b, c);
  printf("x = %.35f\n", quadratic(a, b, c));
}
