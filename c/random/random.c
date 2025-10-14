#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

double drand(double min, double max) {
  double range = (max - min);
  double div = UINT32_MAX / range;
  return min + (arc4random() / div);
}

typedef struct {
  size_t len;
  char **arr;
} String_Array;

String_Array string_array() {
  String_Array a = *(String_Array *)malloc(sizeof(String_Array));
  return a;
}

void append(String_Array *arr, char *elem) {
  arr->len++;
  arr->arr = realloc(arr->arr, arr->len);
  arr->arr[arr->len - 1] = elem;
}

typedef struct {
  bool help;
  bool isInt;
  bool coin;
  double min;
  double max;
} Args;

void parseArgs(int argc, char **argv, Args *args) {
  String_Array remainingArgs = string_array();
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      if (!strncmp(argv[i], "--help", 7) || !strncmp(argv[i], "-h", 3)) {
        args->help = true;
        continue;
      }
      if (!strncmp(argv[i], "-i", 3)) {
        args->isInt = true;
        continue;
      }
      if (!strncmp(argv[i], "-c", 3) || !strncmp(argv[i], "--coin", 7)) {
        args->coin = true;
        continue;
      }
    } else {
      append(&remainingArgs, argv[i]);
    }
  }

  if (remainingArgs.len == 1) {
    args->max = strtod(remainingArgs.arr[0], NULL);
  } else if (remainingArgs.len > 1) {
    args->min = strtod(remainingArgs.arr[0], NULL);
    args->max = strtod(remainingArgs.arr[1], NULL);
  }
}

int main(int argc, char **argv) {
  Args args = {
      .help = false, .isInt = false, .coin = false, .min = 0, .max = 1};
  parseArgs(argc, argv, &args);

  if (args.help) {
    printf("\nUSAGE: random [-i] [--coin] [<min>] [<max>]\n"
           "\n"
           "ARGUMENTS:\n"
           "  <min>          The minimum value for the random number "
           "generator. (default: 0.0)\n"
           "  <max>          The maximum value for the random number "
           "generator. (default: 1.0)\n"
           "\n"
           "OPTIONS:\n"
           "  -i             Should the output be an integer?\n"
           "  -c, --coin     Flip a coin instead of generating a number.\n"
           "  -h, --help     Display this help and exit.\n"
           "\n");
    return 0;
  }

  if (args.coin) {
    if (arc4random_uniform(2) == 1) {
      printf("Heads\n");
    } else {
      printf("Tails\n");
    }
    return 0;
  }

  if (args.min > args.max) {
    fprintf(
        stderr,
        "\033[31mERROR: Min value is larger than max value. (%f > %f)\033[0m\n",
        args.min, args.max);
    return 1;
  }

  if (args.isInt) {
    printf("%d\n", (arc4random() % (uint32_t)(args.max - args.min + 1)) +
                       (uint32_t)args.min);
  } else {
    printf("%f\n", drand(args.min, args.max));
  }

  return 0;
}
