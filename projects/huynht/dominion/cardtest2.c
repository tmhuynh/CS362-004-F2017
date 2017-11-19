#include <stdio.h>
#include "dominion.h"

/* Adventurer Test */

int main() {
	int i;
	int bugs = 0;
	int previousHand, previousDiscard;

	struct gameState *state = newGame();

	state->deck[0][0] = copper;
	state->deck[0][1] = council_room;
	state->deck[0][2] = steward;
	state->deck[0][4] = silver;
	state->deck[0][5] = minion;

	state->hand[0][0] = adventurer;
	previousHand = state->handCount[0];
	previousDiscard = state->discardCount[0];

	playCard(0, 0, 0, 0, state);

	printf("Adventurer Test starting...\n", bugs);

	if ((state->handCount[0] - previousHand) != 1) {
		printf("Treaure cards not added to hand.\n");
		bugs++;
	}

	if ((state->discardCount[0] - previousDiscard) != 2) {
		printf("Incorrect number of cards added to discard.\n");
		bugs++;
	}

	if (bugs > 0)
		printf("Adventurer Test: %d bugs.\n", bugs);
	else
		printf("Adventurer Test: Test was successful.\n");

	return 0;
}
