/**
 * gcc test_helper.c rngs.c dominion.c cardtest2.c -lm -o testing -std=c99
 * Tests card: smithy
 * */
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helper.h"
// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);
// smithyCard(i, currentPlayer, state, handPos);

void testSmithyCard()
{
  struct gameState *state = newGame();
  int *kCards = kingdomCards(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  initializeGame(2, kCards, 1, state);

  cardEffect(smithy, 0, 0, 0, state, 0, 0);
  assertEqual("draws three cards", 8, state->handCount[0]);
  assertEqual("deckCount should be 2", 2, state->deckCount[0]);
}

int main()
{
  testSmithyCard();
  return 0;
}