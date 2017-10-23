#include <stdio.h>
#include "dominion.h"

/* Council Room Test */

int main() {
	int bugs = 0;

	struct gameState *state = newGame();

	int buysBefore, handCountBefore0, handCountBefore1, handCountBefore2;

	int numPlayers = 3;
	int kingdomCards[10] = {adventurer, council_room, mine, remodel, village, smithy, ambassador, embargo, sea_hag, mine};
	int randomSeed = 5;

	state->hand[0][0] = council_room;

	buysBefore = state->numBuys;
	handCountBefore0 = state->handCount[0];
	handCountBefore1 = state->handCount[1];
	handCountBefore2 = state->handCount[2];

	playCard(0, 0, 0, 0, state);

	printf("Council Room Test startings...\n");

	if ((buysBefore - state->numBuys) != 1) {
		printf("buyCount was not changed correctly.\n");
		bugs++;
	}

	if ((handCountBefore0 - state->handCount[0]) != 4) {
		printf("Player's handCount was not changed correctly.\n");
		bugs++;
	}

	if (((handCountBefore1 - state->handCount[1]) != 1) || ((handCountBefore2 - state->handCount[2]) != 2)) {
		printf("Other players' handCounts were not changed correctly.\n");
		bugs++;
	}

	if (bugs > 0)
		printf("Council Room Test: %d bugs.\n", bugs);
	else
		printf("Council Room Test: Test was successful.\n");

	return 0;
}

