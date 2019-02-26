/**
 * gcc test_helper.c rngs.c dominion.c unittest4.c -lm -o testing -std=c99
 * 
 * Tests whoseTurn in dominion.c
 * */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "test_helper.h"

void testWhoseTurn()
{
  struct gameState *state = newGame();
  int *kCards = kingdomCards(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  initializeGame(2, kCards, 1, state);

  assertEqual("initial turn is 0", 0, whoseTurn(state));
  state->whoseTurn = 16;

  assertEqual("initial turn can be set", 16, whoseTurn(state));

  free(state);
}

int main()
{
  testWhoseTurn();
  return 0;
}