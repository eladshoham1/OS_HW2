#include <stdio.h>
#include <pthread.h>
#include "xorlib.h"
#include "allStrings.h"

pthread_mutex_t lock;

int calculateStrXor(void *arg) {
	StringsParts *stringsParts = (StringsParts*)arg;
	int i, res = 0;

	pthread_mutex_lock(&lock);

	// Calculate the xor between all the strings
	for (i = 0; i < stringsParts->numOfStrings; i++) {
		// Calculate the xor between all the characters in the string
		for (char *ch = stringsParts->strings[i]; *ch != EPSILON; ch++) {
	      		res ^= *ch;
		}
	}

    	pthread_mutex_unlock(&lock);

	return res;
}
