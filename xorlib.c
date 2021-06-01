#include <stdio.h>
#include <pthread.h>
#include "xorlib.h"
#include "strXor.h"

pthread_mutex_t lock;

void calculateStrXor(void *arg) {
	StrXor *strXor = (StrXor*)arg;
	int i;

	pthread_mutex_lock(&lock);

	// Calculate the xor between all the strings
	for (i = 0; i < strXor->numOfStrings; i++) {
		// Calculate the xor between all the characters in the string
		for (char *ch = strXor->strings[i]; *ch != EPSILON; ch++) {
	      		strXor->res ^= *ch;
		}
	}

    	pthread_mutex_unlock(&lock);
}
