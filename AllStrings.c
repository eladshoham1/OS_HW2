#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AllStrings.h"

AllStrings initAllStrings() {
	AllStrings allStrings;
	int i;

	for (i = 0; i < NUM_THREADS; i++) {
		allStrings.stringsParts[i].numOfStrings = 0;
	}

	return allStrings;
}

void spliteStringsToParts(AllStrings *allStrings, char **strings, int numOfStrings) {
	int i;

	for (i = 0; i < numOfStrings; i++) {
		addStringToParts(&allStrings->stringsParts[i % NUM_THREADS], strings[i]);
	}
}

void addStringToParts(StringsParts *stringsParts, char *str) {
	stringsParts->strings = (char**)realloc(stringsParts->strings, (stringsParts->numOfStrings + 1) * sizeof(char*));
	if (!stringsParts->strings) {
		fprintf(stderr, "Failed to reallocate\n");
    		return;
	}

	strcpy(stringsParts->strings[stringsParts->numOfStrings], str);
	puts(stringsParts->strings[stringsParts->numOfStrings]); // no
	stringsParts->numOfStrings++;
}

/*

allStrings->stringsParts[i % NUM_THREADS].strings = (char**)realloc(allStrings->stringsParts[i % NUM_THREADS].strings, (allStrings->stringsParts[i % NUM_THREADS].numOfStrings + 1) * sizeof(char*))
if (!allStrings->stringsParts[i % NUM_THREADS].strings) {
	fprintf(stderr, "Failed to reallocate\n");
	return;
}

strcpy(allStrings->stringsParts[i % NUM_THREADS].strings[allStrings->stringsParts[i % NUM_THREADS].numOfStrings], strings[i]);
allStrings->stringsParts[i % NUM_THREADS].numOfStrings++;

*/
