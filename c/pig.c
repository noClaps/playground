// https://en.wikipedia.org/wiki/Pig_(dice_game)

#include <stdio.h>
#include <stdlib.h>

#define BAD_ROLL 1
#define PLAYER_COUNT 2
#define WIN_COUNT 100

uint8_t roll_dice() { return arc4random_uniform(6) + 1; }
size_t won_game(int8_t scores[], size_t len) {
  for (size_t i = 0; i < len; i++) {
    if (scores[i] >= WIN_COUNT) {
      return i + 1;
    }
  }
  return 0;
}

int main() {
  uint8_t current_turn = 1;
  int8_t scores[PLAYER_COUNT] = {0};

  while (!won_game(scores, PLAYER_COUNT)) {
    uint8_t current_roll = 0;
    char hold = 'n';
    int8_t acc = 0;

    printf("Player %d (%d)'s turn\n", current_turn, scores[current_turn - 1]);
    while (hold != 'y') {
      current_roll = roll_dice();
      if (current_roll == BAD_ROLL) {
        acc = 0;
        printf("Rolled %d. Turn ended.\n", BAD_ROLL);
        break;
      }

      acc += current_roll;
      printf("Rolled %d. Current total: %d. Hold? (y/n) ", current_roll, acc);
      char newline;
      while (scanf("%c%c", &hold, &newline)) {
        if (newline == '\n') {
          break;
        }
      }
    }

    scores[current_turn - 1] += acc;
    current_turn = (current_turn % PLAYER_COUNT) + 1;
    printf("\n");
  }

  size_t winner = won_game(scores, PLAYER_COUNT);
  printf("Player %lu wins!\n", winner);
  printf("Score:\n");
  for (size_t i = 0; i < PLAYER_COUNT; i++) {
    printf("  Player %lu: %d\n", i + 1, scores[i]);
  }
}
