/**
 * gcc test_helper.c rngs.c dominion.c cardtest1.c -lm -o testing -std=c99
 * Tests card: adventurer
 * */
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helper.h"
// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);
// int adventurerCard(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int *temphand, int z);

void testAdventurerCard()
{
  struct gameState *state = newGame();
  int *kCards = kingdomCards(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  initializeGame(2, kCards, 1, state);

  cardEffect(adventurer, 0, 0, 0, state, 0, 0);
  assertEqual("discard pile should be 0", 0, state->discardCount[0]);
  assertEqual("handCount should be 7", 7, state->handCount[0]);
  assertEqual("deckCount should be 3", 3, state->deckCount[0]);
}

int main()
{
  testAdventurerCard();
  return 0;
}