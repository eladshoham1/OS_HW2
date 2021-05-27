#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
// #include "xorlib.h"

#define NUM_THREADS (4)
#define EPSILON ('\0')

pthread_mutex_t lock;

void *calculate_strxor(void *arg) {
	int *res = 0;
	char *str;

	pthread_mutex_lock(&lock);
	
	for (str = (char*)arg; *str != EPSILON; str++) {
      		*res ^= *str;
	}
	printf("rtnrsn %d\n", *res);
    	pthread_mutex_unlock(&lock);

	return (void *)res;
}

int main(int argc, char* argv[])
{
    	int i, *res = 0;
    	pthread_t threads[NUM_THREADS];

    	if (argc <= 1) {
    		fprintf(stderr, "There is no strings\n");
    	    	return 0;
    	}
	
	// create all threads one by one
    	for (i = 0; i < NUM_THREADS; i++) {
        	pthread_create(&threads[i], NULL, calculate_strxor, argv[1]);
    	}

	// wait for each thread to complete
    	for (i = 0; i < NUM_THREADS; i++) {
        	pthread_join(threads[i], (void **)&res);
    	}

    	printf("xor of all strings: %d\n", *res);
  	return 0;
}


