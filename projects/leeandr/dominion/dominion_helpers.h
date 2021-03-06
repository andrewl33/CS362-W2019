#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state,
								int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3,
							 struct gameState *state, int handPos, int *bonus);

// cards
int adventurerCard(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int *temphand, int z);
int smithyCard(int i, int currentPlayer, struct gameState *state, int handPos);
int feastCard(int i, struct gameState *state, int currentPlayer, int *temphand, int x, int choice1);
int mineCard(int i, int j, struct gameState *state, int currentPlayer, int choice1, int choice2, int handPos);
int villageCard(int currentPlayer, struct gameState *state, int handPos);
#endif
