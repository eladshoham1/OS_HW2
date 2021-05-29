#include <stdio.h>
#include <pthread.h>
#include "xorlib.h"
#include "allStrings.h"

int main(int argc, char* argv[])
{
    	int i, res = 0, results[NUM_THREADS];
    	pthread_t threads[NUM_THREADS];
	AllStrings *allStrings = NULL;

	// Check if user enter strings
    	if (argc <= 1) {
    		fprintf(stderr, "There is no strings\n");
    	    	return 0;
    	}

	allStrings = initAllStrings(argc - 1);
	if (!allStrings) {
		fprintf(stderr, "Failed to allocate\n");
		return 0;
	}

	// Split argv strings to threads
	splitStringsToThreads(allStrings, argv + 1, argc - 1);

	// Create all threads one by one
    	for (i = 0; i < NUM_THREADS; i++) {
        	pthread_create(&threads[i], NULL, (void*)calculateStrXor, &allStrings->stringsParts[i]);
    	}

	// Wait for each thread to complete
    	for (i = 0; i < NUM_THREADS; i++) {
        	pthread_join(threads[i], (void*)&results[i]);
		res ^= results[i];
    	}

    	printf("xor of all strings: %d\n", res);
	freeMemory(allStrings);
  	return 0;
}
