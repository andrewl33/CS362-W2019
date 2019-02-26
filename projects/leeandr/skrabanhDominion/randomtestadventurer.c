/**
 * gcc rngs.c dominion.c randomtestadventurer.c -lm -o testing -std=c99
 * Tests card: adventurer
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"

void testAdventurerCard(int iterations)
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
  int treasureCountError = 0;
  while (i != iterations)
  {
    // magic number for errors
    cardEffectVal = -100;

    // set random playercount
    int playerCount = (rand() % (MAX_PLAYERS - 2)) + 2;

    // initialize random game
    if (initializeGame(playerCount, kc, rand(), testState) != -1)
    {
      // count treasure cards in hand
      int initTreasureCardCount = 0;
      int endTreasureCardCount = 0;
      int curPlayer = whoseTurn(testState);
      int curHandSize = testState->handCount[curPlayer];

      for (int j = 0; j < curHandSize; j++)
      {
        int curCard = testState->hand[curPlayer][j];

        if (curCard == copper || curCard == silver || curCard == gold)
        {
          initTreasureCardCount++;
        }
      }
      // randomly assign treasure cards to deck
      for (int j = 0; j < testState->deckCount[curPlayer]; j++)
      {
        if (rand() % 2 == 1)
        {
          testState->deck[curPlayer][j] = (rand() % 3) + 4;
        }
      }
      // run cardEffect, -1 and NULLs are used for unused values
      cardEffectVal = cardEffect(adventurer, -1, -1, -1, testState, -1, NULL);

      if (cardEffectVal == -100 || cardEffectVal == -1)
      {
        // send error
        cardEffectError++;
      }
      else
      {
        // check count of treasure cards
        curHandSize = testState->handCount[curPlayer];

        for (int j = 0; j < curHandSize; j++)
        {
          int curCard = testState->hand[curPlayer][j];

          if (curCard == copper || curCard == silver || curCard == gold)
          {
            endTreasureCardCount++;
          }
        }

        // checks for two added treasure cards
        if (endTreasureCardCount - initTreasureCardCount != 2)
        {
          treasureCountError++;
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
  printf("AdventurerCard:\n\tIterations: %d\n", iterations);
  printf("\tErrors: %d\n", initGameError + cardEffectError + treasureCountError);
  if (initGameError > 0)
  {
    printf("\tErrors in initializeGame: %d\n", initGameError);
  }
  if (cardEffectError > 0)
  {
    printf("\tErrors in cardEffect: %d\n", cardEffectError);
  }
  if (treasureCountError > 0)
  {
    printf("\tErrors in adventurerCard: %d\n", treasureCountError);
  }
}

int main()
{
  int iterations = 1000000;

  testAdventurerCard(iterations);
  return 0;
}