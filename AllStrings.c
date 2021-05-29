#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AllStrings.h"

AllStrings *initAllStrings(int totalStrings) {
	AllStrings *allStrings = NULL;
	int i, numOfStrings, size;
	numOfStrings = totalStrings / NUM_THREADS;

	allStrings = (AllStrings*)malloc(sizeof(AllStrings));
	if (!allStrings) {
		fprintf(stderr, "Failed to allocate\n");
	    	return NULL;
	}

	for (i = 0; i < NUM_THREADS; i++) {
		size = totalStrings % NUM_THREADS > i ? numOfStrings + 1 : numOfStrings;
		allStrings->stringsParts[i].strings = (char**)malloc(size * sizeof(char*));
		if (!allStrings->stringsParts[i].strings) {
			fprintf(stderr, "Failed to reallocate\n");
	    		return NULL;
		}

		allStrings->stringsParts[i].numOfStrings = size;
	}

	return allStrings;
}

void spliteStringsToParts(AllStrings *allStrings, char **strings, int numOfStrings) {
	int i, j;

	for (i = 0, j = 0; i < numOfStrings; i++) {
		allStrings->stringsParts[i % NUM_THREADS].strings[j] = strings[i];

		if (i % NUM_THREADS == NUM_THREADS - 1) {
			j++;
		}
	}
}
