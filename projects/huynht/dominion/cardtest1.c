#include <stdio.h>
#include "dominion.h"

/* Smithy Card Test */

int main() {
	int bugs = 0;

	struct gameState *state = newGame();

	int handCountBefore, handCountAfter;

	int numPlayers = 1;
	int kingdomCards[10] = {adventurer, council_room, mine, remodel, village, smithy, ambassador, embargo, sea_hag, mine};
	int randomSeed = 9;

	state->hand[0][0] = smithy;

	handCountBefore = state->handCount[1];

	//printf("Smithy Test Cards in Hand: Count Before -> %d.\n", handCountBefore);

	playCard(0, 0, 0, 0, state);
	handCountAfter = state->handCount[1];

	//printf("Smithy Test Cards Hand: Count After -> %d.\n", handCountAfter);

	printf("Smithy Test startings...\n");

	if ((handCountBefore - handCountAfter) != 3) {
		printf("Player's handCount was not changed correctly.\n");
		bugs++;
	}

	if (bugs > 0)
		printf("Smithy Test: %d bugs.\n", bugs);
	else
		printf("Smithy Test: Test was successful.\n");

	return 0;
}

