#include <stdio.h>
#include <stdlib.h>

const int64_t ITERATIONS = 1000;

double quadratic_c(double cm1, int64_t count) {
  if (count == 0) {
    return cm1 / 2;
  }
  return cm1 / (2 + quadratic_c(cm1, count - 1));
}

double quadratic_bc(double b, double c, int64_t count) {
  if (count == 0) {
    return b;
  }
  return b + c / quadratic_bc(b, c, count - 1);
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
    return 1 + quadratic_c(c - 1, ITERATIONS);
  }

  // x^2 = bx + c
  b = -b;
  c = -c;
  // x = b + c/x
  //   = b + c/(b + c/x)...
  return quadratic_bc(b, c, ITERATIONS);
}

int main(int argc, char **argv) {
  double a = atof(argv[1]);
  double b = atof(argv[2]);
  double c = atof(argv[3]);

  printf("a = %lf, b = %lf, c = %lf\n", a, b, c);
  printf("x = %lf\n", quadratic(a, b, c));
}
