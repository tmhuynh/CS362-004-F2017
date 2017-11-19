#include <stdio.h>
#include "dominion.h"

/* Unit Test for buy card */

int main() {
	int i;
	int bugs, found = 0;

	struct gameState state;

	state.deckCount[0] = 5;
	state.deck[0][0] = copper;
	state.deck[0][1] = copper;
	state.deck[0][2] = copper;
	state.deck[0][3] = copper;
	state.deck[0][4] = copper;
	state.deck[0][5] = copper;
	state.deck[0][6] = copper;

	state.deck[0][7] = estate;
	state.deck[0][8] = estate;
	state.deck[0][9] = estate;

	buyCard(mine, &state);

	printf("Starting test for Unit Test 2...\n");

	if (state.deckCount[0] > 11) {
		printf("The player has received too many cards.\n");
		bugs++;
	}

	for (i = 0; i < state.deckCount[0]; i++) {
		if (state.deck[0][i] == mine) {
			found = 1;
			break;
		}
	}

	if (!found) {
		printf("Card was not added to deck.\n");
		bugs++;
	}

	if (bugs > 0)
		printf("Unit Test 2: %d bugs.\n", bugs);
	else
		printf("Unit Test 2 was successful.\n");

	return 0;
}

