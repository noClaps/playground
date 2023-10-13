#include <stdio.h>

int main(void) {
  int height, length, width;

  printf("Enter height of box: ");
  scanf("%d", &height);
  printf("Enter length of box: ");
  scanf("%d", &length);
  printf("Enter width of box: ");
  scanf("%d", &width);

  const float volume = height * length * width;
  const float weight = volume / 166;

  printf("Dimensions: %dx%dx%d\n", length, width, height);
  // Can use %.0f to display floats as integers
  printf("Volume (cubic inches): %.0f\n", volume);
  printf("Dimensional weight (pounds): %f\n", weight);

  return 0;
}