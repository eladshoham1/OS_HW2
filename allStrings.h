#ifndef _STRLIB_H_
#define _STRLIB_H_

#define NUM_THREADS (4)

typedef struct {
    char **strings;
    int numOfStrings;
} StringsParts;

typedef struct {
    StringsParts stringsParts[NUM_THREADS];
} AllStrings;

// Allocate parts of strings for each thread
AllStrings *initAllStrings(char **strings, int totalStrings);

// Split all strings equally between the threads
void splitStringsToParts(AllStrings *allStrings, char **strings, int numOfStrings);

// Free the memory of all the strings parts
void freeMemory(AllStrings *allStrings);

#endif
