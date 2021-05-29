#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "xorlib.h"
#include "AllStrings.h"

pthread_mutex_t lock;

void calculate_strxor(void *arg) {
	StringsParts *stringsParts = (StringsParts*)arg;
	int i;
	char *str;

	pthread_mutex_lock(&lock);

	for (i = 0; i < stringsParts->numOfStrings; i++) {
		puts(stringsParts->strings[i]);
		for (str = stringsParts->strings[i]; *str != EPSILON; str++) {
	      		res ^= *str;
		}
	}

    	pthread_mutex_unlock(&lock);
}
