#include <stdio.h>
#include <stdlib.h>
#include "strXor.h"

StrXor *initStrXor(char **strings, int numOfStrings, int numOfThreads) {
	StrXor *strXor = NULL;
	int i, stringsPerThread, size;
	stringsPerThread = numOfStrings / numOfThreads;

	strXor = (StrXor*)malloc(numOfThreads * sizeof(StrXor));
	if (!strXor) {
	    	return NULL;
	}

	for (i = 0; i < numOfThreads; i++) {
		// If the number of strings is not divided by the number of threads without a remainder we put the remainder in the first threads
		size = numOfStrings % numOfThreads > i ? stringsPerThread + 1 : stringsPerThread;

		// Allocate the exact size according to the number of strings that should be in the thread
		strXor[i].strings = (char**)malloc(size * sizeof(char*));
		if (!strXor[i].strings) {
	    		return NULL;
		}

		strXor[i].numOfStrings = size;
		strXor[i].res = 0;
	}
	
	splitStringsToParts(strXor, strings, numOfStrings, numOfThreads);	
	return strXor;
}

void splitStringsToParts(StrXor *strXor, char **strings, int numOfStrings, int numOfThreads) {
	int i, j;

	for (i = 0; i < numOfThreads; i++) {
		for (j = 0; j < strXor[i].numOfStrings; j++) {
			strXor[i].strings[j] = strings[i % numOfThreads + j];
		}
	}
}

void freeMemory(StrXor *strXor, int numOfThreads) {
	int i;

	for (i = 0; i < numOfThreads; i++) {
		free(strXor[i].strings);
	}

	free(strXor);
}
