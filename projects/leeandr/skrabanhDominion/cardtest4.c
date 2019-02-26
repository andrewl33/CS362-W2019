/**
 * gcc test_helper.c rngs.c dominion.c cardtest4.c -lm -o testing -std=c99
 * Tests card: Village
 * Uses cardEffect as entry point
 * */
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helper.h"
// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
// int villageCard(int currentPlayer, struct gameState *state, int handPos);

void testVillageCard()
{
  struct gameState *state = newGame();
  int *kCards = kingdomCards(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  initializeGame(2, kCards, 1, state);

  cardEffect(village, 0, 0, 0, state, 0, 0);
  assertEqual("adds and removes a card to hand", 5, state->handCount[0]);
  assertEqual("a card is played", 1, state->playedCardCount);
  assertEqual("removes one card from the deck", 4, state->deckCount[0]);
  assertEqual("should get an extra 2 actions", 1 + 2, state->numActions);
}

int main()
{
  testVillageCard();

  return 0;
}