#ifndef RANDOM_TEST_HELPER_H
#define RANDOM_TEST_HELPER_H

#include "dominion.h"
// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
// struct TestCardEffectParams
// {
//   int card;
//   int choice1;
//   int choice2;
//   int choice3;
//   struct gameState *state;
//   int handPos;
//   int *bonus;
// };

// struct TestCardEffectRanges
// {
//   int card;
//   int choice1Low;
//   int choice2Low;
//   int choice3Low;
//   int handPosLow;
//   int *bonus;
//   int choice1High;
//   int choice2High;
//   int choice3High;
// };

void assertEqual(char *message, int expected, int actual);
// struct TestCardEffectParams *randomTestCardEffectParams(struct TestCardEffectRanges *cardEffectRanges);
// // struct gameState *randomGameState(struct TestGameStateRanges *gameStateRanges);
#endif