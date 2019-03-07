/**
 * gcc test_helper.c rngs.c dominion.c greathallcardtest.c -lm -o testing -std=c99
 * Tests card: Great Hall
 * Uses cardEffect as entry point
 * */
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helper.h"
// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
// int greathallEffect(int handPos, struct gameState *state)

void testGreatHallCard()
{
  struct gameState *state = newGame();
  int *kCards = kingdomCards(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  initializeGame(2, kCards, 1, state);

  int prevStateActions = state->numActions;
  cardEffect(great_hall, 0, 0, 0, state, 0, 0);
  assertEqual("adds and removes a card to hand", 5, state->handCount[0]);
  assertEqual("should get an extra 1 action", prevStateActions + 1, state->numActions);
}

int main()
{
  testGreatHallCard();

  return 0;
}