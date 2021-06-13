#ifndef _STRLIB_H_
#define _STRLIB_H_

typedef struct {
	char **strings;
	int numOfStrings;
	int res;
} StrXor;

// Allocate parts of strings for each thread
StrXor *initStrXor(char **strings, int numOfStrings, int numOfThreads);

// Split all strings equally between the threads
void splitStringsToThreads(StrXor *strXor, char **strings, int numOfStrings, int numOfThreads);

// Free the memory of all the strings parts
void freeMemory(StrXor *strXor, int numOfThreads);

#endif
