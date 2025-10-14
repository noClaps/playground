#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  size_t len;
  char *str;
} String;

String string(const char *input) {
  String output;
  output.len = asprintf(&output.str, "%s", input);
  return output;
}

void print_string(const char* fmt, String string) {
    printf(fmt, string.str);
}

bool eq_string(String a, String b) {
    if (a.len != b.len) return 0;

    // Return not because strncmp returns false if the values are the same and
    // true if they're different. So to check if they're equal we have to
    // negate this.
    return !strncmp(a.str, b.str, a.len);
}

void print_error(const char* fmt, String string) {
    char* out;
    asprintf(&out, fmt, string.str);
    fprintf(stderr, "\033[31m%s", out);

}

void print_error_c(const char* fmt, char c) {
    char* out;
    asprintf(&out, fmt, c);
    fprintf(stderr, "\033[31m%s", out);
}
