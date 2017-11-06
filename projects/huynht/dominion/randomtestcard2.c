#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_TESTS 500
#define GAME_LIMIT 6

/* Mine Random Test */

int main() {
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int i1, i2, players, seed, player = 0, retVal = 0, count = 0, failures = 0, success = 0;
	struct gameState * gState;

	printf("Running Random Test for Mine\n");

	for(i1 = 0, failures = 0, success = 0 ; i1 < NUM_TESTS ; i1++ ) {
		players = rand() % 4;
		seed = rand();
		gState = malloc(sizeof(struct gameState));
		initializeGame(players, k, seed, gState);

      gState->deckCount[player] = rand() % MAX_DECK;
		gState->discardCount[player] = rand() % MAX_DECK;
		gState->handCount[player] = rand() % MAX_HAND;

		count = 0;

		for(i2 = 0 ; i2 < gState -> handCount[player]; i2++) {
			if (gState->hand[player][i2] == silver)
				count++;
		}

		retVal = cardEffect(mine, copper, silver, 1, gState, 0, 0);
		if(retVal != 0) {
			if ((getCost(gState->hand[player][copper]) + 3) > getCost(silver)) {
				printf("Test %i cut short\n", i1);
			} else {
				printf("%d test failed\n", i1);
				//printf("cardEffect returned %d\n", retVal);
				failures++;
			}
		} else {
			for(i2 = 0 ; i2 < gState->handCount[player]; i2++) {
				if (gState->hand[player][i2] == copper) {
					count--;
				}
			}

			if ( count < 0 ) {
				success++;
			}
		}

		free(gState);

		printf("%d Tests Completed\n", i1);
	}

	printf("\n%d failures and %d successful cases of mMine.\n", failures, success);
}
