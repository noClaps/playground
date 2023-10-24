#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 7

char palindromeCheck(int number) {
  int begin;
  char num[MAX_LENGTH], revnum[MAX_LENGTH];

  sprintf(num, "%d", number);

  int length = 0;
  while (num[length] != '\0') {
    length++;
  }

  int end = length - 1;

  for (begin = 0; begin < length; begin++) {
    revnum[begin] = num[end];
    end--;
  }

  revnum[begin] = '\0';

  return strcmp(num, revnum);
}

int main() {
  int maxI = 0, maxJ = 0, currentMax = 0;

  for (int i = 999; i > 100; i--) {
    for (int j = i; j > 100; j--) {
      if (palindromeCheck(i * j) == 0 && i * j > currentMax) {
        currentMax = i * j;
        maxI = i;
        maxJ = j;
      }
    }
  }

  printf("%d\n", currentMax);
  return 0;
}