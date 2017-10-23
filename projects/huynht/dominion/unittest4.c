#include <stdio.h>
#include "dominion.h"

/* Unit test for isGameOver */

int main() {
	int bugs = 0;

	struct gameState state1;
	struct gameState state2;

	state1.supplyCount[province] = 0;
	state2.supplyCount[adventurer] = 0;
	state2.supplyCount[mine] = 0;
	state2.supplyCount[copper] = 0;

	printf("Starting test for Unit Test 4...\n");

	if (isGameOver(&state1) != 1) {
		printf("The first game state didn't check correctly.\n");
		bugs++;
	}

	if (isGameOver(&state2) != 1) {
		printf("The second game state didn't check correctly.\n");
		bugs++;
	}

	if (bugs > 0)
		printf("Unit Test 4: There were %d bugs.\n", bugs);
	else
		printf("Unit Test 4: The test was successful.\n");

	return 0;
}

