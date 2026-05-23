#include <stdio.h>

int main(int argc, char **argv) {
  printf("Your channel's RSS feed is:\n");
  printf("https://www.youtube.com/feeds/videos.xml?channel_id=%s\n", argv[1]);
}
