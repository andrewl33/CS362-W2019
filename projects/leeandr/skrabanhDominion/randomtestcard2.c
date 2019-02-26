/**
 * Smithy Random Test Case
 * Tests:
 * Draws three cards
 * Discards 1 card
 * 
 * gcc rngs.c dominion.c randomtestcard2.c -lm -o testing -std=c99
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"

void testSmithyCard(int iterations)
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

      // run cardEffect, -1 and NULLs are used for unused values
      cardEffectVal = cardEffect(smithy, -1, -1, -1, testState, 0, NULL);

      if (cardEffectVal == -100 || cardEffectVal == -1)
      {
        // send error
        cardEffectError++;
      }
      else
      {
        if (initCardCount + 2 != testState->handCount[curPlayer])
        {
          deckSizeError++;
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
  int errorCount = initGameError + cardEffectError + deckSizeError;

  printf("SmithyCard:\n\tIterations: %d\n", iterations);
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
    printf("\tErrors in smithyCard deck size: %d\n", deckSizeError);
  }
}

int main()
{
  int iterations = 1000000;

  testSmithyCard(iterations);
  return 0;
}