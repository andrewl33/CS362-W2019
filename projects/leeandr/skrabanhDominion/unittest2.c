/**
 * gcc test_helper.c rngs.c dominion.c unittest2.c -lm -o testing -std=c99
 * 
 * Tests shuffle in dominion.c
 * */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "test_helper.h"

void testShuffle()
{
  struct gameState *state = newGame();
  struct gameState *state_1 = newGame();
  int *kCards = kingdomCards(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  assertEqual("returns error on empty state", -1, shuffle(1, state));

  initializeGame(1, kCards, 1, state);
  initializeGame(1, kCards, 1, state_1);
  assertEqual("returns error on initialized, but empty deck", -1, shuffle(1, state));

  state->deckCount[1] = 5;
  state_1->deckCount[1] = 5;
  assertEqual("empty user deck still runs", 0, shuffle(1, state));
  shuffle(1, state_1);

  int difference = 0;

  for (int i = 0; i < 5; i++)
  {
    difference += state->deck[0][i] - state_1->deck[0][i];
  }

  assertEqual("state shuffle should be equal", 0, difference);

  free(state);
  free(state_1);
  free(kCards);
}

int main()
{
  testShuffle();
  return 0;
}