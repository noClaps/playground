#include "../lib/string.c"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int charset(String password) {
  int total_charset = 0;

  // Uppercase
  bool has_upper = false;
  for (size_t i = 0; i < password.len; i++) {
    if (isupper(password.str[i])) {
      has_upper = true;
      break;
    }
  }
  if (has_upper) {
    printf("\033[32m✓ Has uppercase\n\033[0m");
    total_charset += 26;
  } else {
    printf("\033[31m✕ does not have uppercase\n\033[0m");
  }

  // Lowercase
  bool has_lower = false;
  for (size_t i = 0; i < password.len; i++) {
    if (islower(password.str[i])) {
      has_lower = true;
      break;
    }
  }
  if (has_lower) {
    printf("\033[32m✓ Has lowercase\n\033[0m");
    total_charset += 26;
  } else {
    printf("\033[31m✕ does not have lowercase\n\033[0m");
  }

  // Numbers
  bool has_number = false;
  for (size_t i = 0; i < password.len; i++) {
    if (isnumber(password.str[i])) {
      has_number = true;
      break;
    }
  }
  if (has_number) {
    printf("\033[32m✓ Has numbers\n\033[0m");
    total_charset += 10;
  } else {
    printf("\033[31m✕ does not have numbers\n\033[0m");
  }

  bool has_special = false;
  for (size_t i = 0; i < password.len; i++) {
    if (!isalnum(password.str[i])) {
      has_special = true;
      break;
    }
  }
  if (has_special) {
    printf("\033[32m✓ Has special characters\n\033[0m");
    total_charset += 33;
  } else {
    printf("\033[31m✕ does not have special characters\n\033[0m");
  }

  return total_charset;
}

String rating(double entropy) {
  if (entropy < 20)
    return string("\033[31mVery weak\033[0m");
  if (entropy < 40)
    return string("\033[31mWeak\033[0m");
  if (entropy < 60)
    return string("\033[33mOkay\033[0m");
  if (entropy < 80)
    return string("\033[32mStrong\033[0m");
  return string("\033[32mVery strong\033[0m");
}

typedef struct {
  bool help;
  String password;
} Args;

void parse_args(int argc, char **argv, Args *args) {
  for (int i = 1; i < argc; i++) {
    if (!strncmp(argv[i], "--help", 7) || !strncmp(argv[i], "-h", 3)) {
      args->help = true;
    } else {
      args->password = string(argv[i]);
    }
  }
};

int main(int argc, char **argv) {
  Args args = {.help = false, .password = string("")};
  parse_args(argc, argv, &args);

  if (args.help) {
    printf("\n"
           "USAGE: psc <password>\n"
           "\n"
           "ARGUMENTS:\n"
           "  <password>     The password to check strength of.\n"
           "\n"
           "OPTIONS:\n"
           "  -h, --help     Display this help and exit.\n"
           "\n");
    return 0;
  }

  if (eq_string(args.password, string(""))) {
    fprintf(stderr, "\033[31mERROR: Please enter a password\033[0m\n");
    return 1;
  }

  int total_charset = charset(args.password);
  double entropy = log2(pow((double)total_charset, (double)args.password.len));
  String pwd_rating = rating(entropy);

  printf("\nPassword entropy: %f\n", entropy);
  print_string("Password rating: %s\n", pwd_rating);

  return 0;
}
