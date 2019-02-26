/**
 * gcc test_helper.c rngs.c dominion.c unittest1.c -lm -o testing -std=c99
 * 
 * Tests newGame in dominion.c
 * */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "test_helper.h"

void testNewGame()
{
  struct gameState *state = newGame();
  assertEqual("state is not null", state != NULL, 1);
  assertEqual("state is sizeof gameState", sizeof(*state), sizeof(struct gameState));
  free(state);
}

int main()
{
  testNewGame();
  return 0;
}