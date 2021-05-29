#ifndef _STRLIB_H_
#define _STRLIB_H_

typedef struct {
    char **strings;
    int numOfStrings;
} StringsParts;

typedef struct {
    StringsParts stringsParts[NUM_THREADS];
} AllStrings;

AllStrings initAllStrings();
void spliteStringsToParts(AllStrings *allStrings, char **strings, int numOfStrings);

#endif

