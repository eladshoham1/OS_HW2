#ifndef _STRLIB_H_
#define _STRLIB_H_

#define NUM_THREADS (4)
#define EPSILON ('\0')

typedef struct {
    char **strings;
    int numOfStrings;
} StringsParts;

typedef struct {
    StringsParts stringsParts[NUM_THREADS];
} AllStrings;

AllStrings *initAllStrings(int totalStrings);
void spliteStringsToParts(AllStrings *allStrings, char **strings, int numOfStrings);

#endif

