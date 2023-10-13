#include <stdio.h>

int main(void) {
  const int height = 8;
  const int length = 12;
  const int width = 10;
  const float volume = height * length * width;
  const float weight = volume / 166;

  printf("Dimensions: %dx%dx%d\n", length, width, height);
  // Can use %.0f to display floats as integers
  printf("Volume (cubic inches): %.0f\n", volume);
  printf("Dimensional weight (pounds): %f\n", weight);

  return 0;
}