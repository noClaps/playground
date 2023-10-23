#include <stdio.h>

int main(int argc, char *argv[]) {
  // Print channel RSS feed to console
  printf("Your channel's RSS feed is:\n");
  printf("https://www.youtube.com/feeds/videos.xml?channel_id=%s\n", argv[1]);

  return 0;
}
