#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "xorlib.h"

/*pthread_mutex_t lock;

int calculate_strxor(char *str) {
	int res = 0;

	pthread_mutex_lock(&lock);

	for (char *ch = str; *ch != '\0'; ch++)
      		res ^= *ch;

    	pthread_mutex_unlock(&lock);

	return res;
}*/
