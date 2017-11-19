#include <stdio.h>
#include "dominion.h"

/* Unit Test for supplyCount */

int main() {
	int stateBefore, stateAfter;

	struct gameState state;

	state.supplyCount[adventurer] = 10;
	stateBefore = supplyCount(adventurer, &state);

	state.supplyCount[adventurer] = 7;
	stateAfter = supplyCount(adventurer, &state);

	printf("Starting test for Unit Test 3...\n");

	if ((stateBefore - stateAfter) != 3)
		printf("Unit Test 3: Supply count is not correct.\n");
	else
		printf("Unit Test 3: Test was successful.\n");

	return 0;
}
