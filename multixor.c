#include <stdio.h>
#include <pthread.h>
#include "xorlib.h"
#include "strXor.h"

int main(int argc, char* argv[])
{
    	pthread_t threads[NUM_THREADS];
	StrXor *strXor = NULL;
    	int i, res = 0;

	// Check if user enter strings
    	if (argc <= 1) {
    		fprintf(stderr, "There is no strings\n");
    	    	return 0;
    	}

	strXor = initStrXor(argv + 1, argc - 1, NUM_THREADS);
	if (!strXor) {
		fprintf(stderr, "Failed to allocate\n");
		return 0;
	}

	// Create all threads one by one
    	for (i = 0; i < NUM_THREADS; i++) {
        	pthread_create(&threads[i], NULL, (void*)calculateStrXor, &strXor[i]);
    	}

	// Wait for each thread to complete
    	for (i = 0; i < NUM_THREADS; i++) {
        	pthread_join(threads[i], NULL);
		res ^= strXor[i].res;
    	}

    	printf("xor of all strings: %d\n", res);
	freeMemory(strXor, NUM_THREADS);
  	return 0;
}
