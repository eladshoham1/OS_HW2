#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "xorlib.h"
#include "AllStrings.h"

int main(int argc, char* argv[])
{
    	int i, res = 0, results[NUM_THREADS];
    	pthread_t threads[NUM_THREADS];
	AllStrings *allStrings = initAllStrings(argc - 1);

    	if (argc <= 1) {
    		fprintf(stderr, "There is no strings\n");
    	    	return 0;
    	}

	spliteStringsToParts(allStrings, argv + 1, argc - 1);

	// create all threads one by one
    	for (i = 0; i < NUM_THREADS; i++) {
        	pthread_create(&threads[i], NULL, (void*)calculate_strxor, &allStrings->stringsParts[i]);
    	}

	// wait for each thread to complete
    	for (i = 0; i < NUM_THREADS; i++) {
        	pthread_join(threads[i], (void*)&results[i]);
		res ^= results[i];
    	}

    	printf("xor of all strings: %d\n", res);
  	return 0;
}


