#include <stdio.h>
#include <stdlib.h>
#include "allStrings.h"

AllStrings *initAllStrings(int totalStrings) {
	AllStrings *allStrings = NULL;
	int i, numOfStrings, size;
	numOfStrings = totalStrings / NUM_THREADS;

	allStrings = (AllStrings*)malloc(sizeof(AllStrings));
	if (!allStrings) {
	    	return NULL;
	}

	for (i = 0; i < NUM_THREADS; i++) {
		// If the number of strings is not divided by the number of threads without a remainder we put the remainder in the first threads
		size = totalStrings % NUM_THREADS > i ? numOfStrings + 1 : numOfStrings;

		// Allocate the exact size according to the number of strings that should be in the thread
		allStrings->stringsParts[i].strings = (char**)malloc(size * sizeof(char*));
		if (!allStrings->stringsParts[i].strings) {
	    		return NULL;
		}

		allStrings->stringsParts[i].numOfStrings = size;
	}

	return allStrings;
}

void splitStringsToThreads(AllStrings *allStrings, char **strings, int numOfStrings) {
	int i, j;

	for (i = 0, j = 0; i < numOfStrings; i++) {
		allStrings->stringsParts[i % NUM_THREADS].strings[j] = strings[i];
		
		// If is this the last thread raise j by one for the next string in each thread
		if (i % NUM_THREADS == NUM_THREADS - 1) {
			j++;
		}
	}
}

void freeMemory(AllStrings *allStrings) {
	int i;

	for (i = 0; i < NUM_THREADS; i++) {
		free(allStrings->stringsParts[i].strings);
	}

	free(allStrings);
}
