/**
 * gcc test_helper.c rngs.c dominion.c councilroomcardtest.c -lm -o testing -std=c99
 * Tests card: Great Hall
 * Uses cardEffect as entry point
 * */
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helper.h"
// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
// int councilroomEffect(int handPos, struct gameState *state)

void testCouncilRoomCard()
{
  struct gameState *state = newGame();
  int *kCards = kingdomCards(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  initializeGame(4, kCards, 1, state);

  int initBuys = state->numBuys;

  for (int i = 1; i < 4; i++)
  {
    state->handCount[i] = 5;
  }

  cardEffect(council_room, 0, 0, 0, state, 0, 0);
  assertEqual("adds 4 and removes a card to hand", 8, state->handCount[0]);
  int i;
  for (i = 1; i < 4; i++)
  {
    assertEqual("should add one card to player", 6, state->handCount[i]);
  }

  assertEqual("Should add a buy", initBuys, state->numBuys - 1);
}

int main()
{
  testCouncilRoomCard();

  return 0;
}