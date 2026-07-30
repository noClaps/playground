#include <stdio.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <string>\n", argv[0]);
    return 0;
  }
  printf("Your channel's RSS feed is:\n");
  printf("https://www.youtube.com/feeds/videos.xml?channel_id=%s\n", argv[1]);
}
