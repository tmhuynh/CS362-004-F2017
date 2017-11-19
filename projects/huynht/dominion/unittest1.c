#include <stdio.h>
#include "dominion.h"

/* Unit test for initializeGame */

int main() {
	int i;
	int testResult;
	int bugs = 0;
	int numberPlayers = 3;
	int kingdomCards[10] = {adventurer, council_room, mine, remodel, village, smithy, ambassador, embargo, sea_hag, mine};
	int randomSeed = 5;

	struct gameState *state = newGame();

	testResult = initializeGame(numberPlayers, kingdomCards, randomSeed, state);

	printf("Starting test for Unit Test 1...\n");

	if (state->numPlayers != numberPlayers) {
		printf("Number of players not properly initialized.\n");
		bugs++;
	}

	if (testResult == -1) {
		printf("Kingdom cards are returned as containing copies.\n");
		bugs++;
	}

	if ((state->supplyCount[curse] != 10) && (numberPlayers == 2)) {
		printf("Supply count of curse didn't initalize correctly.\n");
		bugs++;
	} else if ((state->supplyCount[curse] != 20) && (numberPlayers == 3)) {
		printf("Supply count of curse didn't initalize correctly.\n");
		bugs++;
	} else if (state->supplyCount[curse] != 30) {
		printf("Supply count of curse didn't initalize correctly.\n");
		bugs++;
	}

	if ((numberPlayers == 2) && (state->supplyCount[estate] != 8) && (state->supplyCount[duchy] != 8) && (state->supplyCount[province] != 8)) {
		printf("Supply count of victory cards didn't initialize correctly.\n");
		bugs++;
	} else if ((state->supplyCount[estate] != 12) && (state->supplyCount[duchy] != 12) && (state->supplyCount[province] != 12)) {
		printf("Supply count of victory cards didn't initialize correctly.\n");
		bugs++;
	}

	if (state->supplyCount[copper] != 60-(numberPlayers*7) || state->supplyCount[silver] != 40 || state->supplyCount[gold] != 30) {
		printf("Supply count of treasure cards didn't initialize correctly.\n");
		bugs++;
	}

	if ((state->deckCount[0] != 10) || (state->deckCount[1] != 10) && (state->deckCount[2] != 10)) {
		printf("Player deck counts were not initialized correctly.\n");
		bugs++;
	}

	if ((state->deck[0][0] != copper) || (state->deck[0][3] != estate)) {
		printf("Player 1 deck was not initialized correctly.\n");
		bugs++;
	}

	if ((state->deck[1][0] != copper) || (state->deck[1][3] != estate)) {
		printf("Player 2 deck was not initialized correctly.\n");
		bugs++;
	}

	if ((state->deck[2][0] != copper) || (state->deck[2][3] != estate)) {
		printf("Player 3 deck was not initialized correctly.\n");
		bugs++;
	}

	if (state->embargoTokens[0] != 0) {
		printf("Embargo tokens were not initialized correctly.\n");
		bugs++;
	}

	if (whoseTurn != 0) {
		printf("First player not set to the first turn.\n");
		bugs++;
	}

	if (bugs > 0) {
		printf("Unit Test 1: %d bugs.\n", bugs);
	} else {
		printf("Unit Test 1: Test was successful.");
	}

	return 0;
}
