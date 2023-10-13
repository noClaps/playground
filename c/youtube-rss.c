#include <stdio.h>

int main(void) {
  // Declare variables
  char channelId[24];

  // Request input of channel ID
  printf("Enter channel ID\n");
  scanf("%s", channelId);

  // Print channel RSS feed to console
  printf("Your channel's RSS feed is:\n");
  printf("https://www.youtube.com/feeds/videos.xml?channel_id=");
  puts(channelId);

  return 0;
}
