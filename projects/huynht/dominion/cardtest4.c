#include <stdio.h>
#include "dominion.h"

/* Gardens Card Test */

int main() {
	int bugs = 0;

	struct gameState *state1 = newGame();
	struct gameState *state2 = newGame();

	state1->hand[0][0] = gardens;

	memcpy(state2, state1, sizeof(struct gameState));

	playCard(0, 0, 0, 0, state1);

	printf("Gardens Test starting...\n");

	if (memcmp(state1, state2, sizeof(struct gameState)) != 0) {
		printf("The game state changed after card was played.\n");
		bugs++;
	}

	if (bugs > 0)
		printf("Gardens Test: %d bugs.\n", bugs);
	else
		printf("Gardens Test: Test was successful.\n");

	return 0;
}

