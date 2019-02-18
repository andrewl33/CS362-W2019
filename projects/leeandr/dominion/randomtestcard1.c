/**
 * Village Random Test Case
 * Tests:
 * Draws one card
 * Gives two actions
 * Discards village card
 * 
 * gcc rngs.c dominion.c randomtestcard1.c -lm -o testing -std=c99
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"

void testVillageCard(int iterations)
{

  srand(time(NULL));
  // build gamestate
  struct gameState *testState = newGame();
  int *kc = kingdomCards(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  int i = 0;
  int cardEffectVal;
  // error values
  int initGameError = 0;
  int cardEffectError = 0;
  int deckSizeError = 0;
  int actionCountError = 0;
  while (i != iterations)
  {
    // magic number for errors
    cardEffectVal = -100;

    // set random playercount
    int playerCount = (rand() % (MAX_PLAYERS - 2)) + 2;

    // initialize random game
    if (initializeGame(playerCount, kc, rand(), testState) != -1)
    {
      // count actions

      int curPlayer = whoseTurn(testState);
      int initCardCount = testState->handCount[curPlayer];
      int initNumActions = rand() % 100; // very arbitrary
      testState->numActions = initNumActions;

      // run cardEffect, -1 and NULLs are used for unused values
      cardEffectVal = cardEffect(village, -1, -1, -1, testState, 0, NULL);

      if (cardEffectVal == -100 || cardEffectVal == -1)
      {
        // send error
        cardEffectError++;
      }
      else
      {
        if (initCardCount != testState->handCount[curPlayer])
        {
          deckSizeError++;
        }

        if (initNumActions + 2 != testState->numActions)
        {
          actionCountError++;
        }
      }
    }
    else
    {
      initGameError++;
    }

    i++;
  }

  // clean
  free(testState);
  free(kc);

  // print results
  int errorCount = initGameError + cardEffectError + deckSizeError + actionCountError;

  printf("VillageCard:\n\tIterations: %d\n", iterations);
  printf("\tErrors: %d\n", errorCount);
  if (initGameError > 0)
  {
    printf("\tErrors in initializeGame: %d\n", initGameError);
  }
  if (cardEffectError > 0)
  {
    printf("\tErrors in cardEffect: %d\n", cardEffectError);
  }
  if (deckSizeError > 0)
  {
    printf("\tErrors in villageCard deck size: %d\n", deckSizeError);
  }
  if (actionCountError > 0)
  {
    printf("\tErrors in villageCard action count: %d\n", actionCountError);
  }
}

int main()
{
  int iterations = 1000000;

  testVillageCard(iterations);
  return 0;
}