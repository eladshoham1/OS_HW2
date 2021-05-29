#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AllStrings.h"

AllStrings initAllStrings() {
	AllStrings allStrings[NUM_THREADS];
	int i;

	for (i = 0; i < NUM_THREADS; i++) {
		allStrings[i].numOfStrings = 0;
	}

	return allStrings;
}

void spliteStringsToParts(AllStrings *allStrings, char **strings, int numOfStrings) {
	int i;

	for (i = 0; i < numOfStrings; i++) {
		allStrings[i % NUM_THREADS].strings = (char**)realloc(allStrings[i % NUM_THREADS].strings, (allStrings[i % NUM_THREADS].numOfStrings + 1) * sizeof(char*));
		if (!allStrings[i % NUM_THREADS].strings) {
			fprintf(stderr, "Failed to reallocate\n");
	    		return 0;
		}

		strcpy(allStrings[i % NUM_THREADS].strings[allStrings[i % NUM_THREADS].numOfStrings], strings[i]);
		allStrings[i % NUM_THREADS].numOfStrings++;
	}
}
