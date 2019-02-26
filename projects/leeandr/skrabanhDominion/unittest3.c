/**
 * gcc test_helper.c rngs.c dominion.c unittest3.c -lm -o testing -std=c99
 * 
 * Tests fullDeckCount in dominion.c
 * */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "test_helper.h"

void testFullDeckCount()
{
  struct gameState *state = newGame();
  int *kCards = kingdomCards(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  initializeGame(2, kCards, 1, state);

  assertEqual("counts 0 for no cards", 0, fullDeckCount(0, 11, state));
  assertEqual("counts 7 for initial copper", 7, fullDeckCount(0, copper, state));

  memcpy(state->discard[0], state->deck[0], sizeof(state->deck[0]));
  state->discardCount[0] = 10;
  assertEqual("double copper size", 14, fullDeckCount(0, copper, state));

  free(state);
}

int main()
{
  testFullDeckCount();
  return 0;
}