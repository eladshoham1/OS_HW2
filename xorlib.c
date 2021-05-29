#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "xorlib.h"
#include "AllStrings.h"

pthread_mutex_t lock;

int calculate_strxor(void *arg) {
	StringsParts *stringsParts = (StringsParts*)arg;
	int i, res = 0;

	pthread_mutex_lock(&lock);

	for (i = 0; i < stringsParts->numOfStrings; i++) {
		for (char *ch = stringsParts->strings[i]; *ch != EPSILON; ch++) {
	      		res ^= *ch;
		}
	}

    	pthread_mutex_unlock(&lock);

	return res;
}
