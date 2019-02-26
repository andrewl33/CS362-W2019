/**
 * gcc test_helper.c rngs.c dominion.c cardtest3.c -lm -o testing -std=c99
 * Tests card: Mine
 * Uses cardEffect as entry point
 * */
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helper.h"
// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
// int mineCard(i, j, state, currentPlayer, choice1, choice2, handPos);

void testMineCard()
{
  struct gameState *state = newGame();
  int *kCards = kingdomCards(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  initializeGame(2, kCards, 1, state);

  assertEqual("province should return error", -1, cardEffect(mine, copper, province, adventurer, state, 0, 0));
  assertEqual("out of bounds card should return error", -1, cardEffect(mine, adventurer, smithy, -1, state, 0, 0));
  assertEqual("cost is greater should return error", -1, cardEffect(mine, province, copper, gold, state, 0, 0));
  state->hand[0][copper] = 5;
  assertEqual("valid cards should run without error", 0, cardEffect(mine, copper, gold, copper, state, 0, 0));
}

int main()
{
  testMineCard();

  return 0;
}