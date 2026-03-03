#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define LIMIT 100000000

int main() {
	int counter = 1;

	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);

	#pragma omp parallel for
	for (int j=0; j<12; ++j) {
		while (counter < LIMIT) {
				
			int val;
		       
			if (pthread_mutex_lock(&mutex))
				perror("mutex lock\n");
			val = counter;
			counter++;
			if (pthread_mutex_unlock(&mutex))
				perror("mutex unlock\n");

			// Do some silly local computation
			for (int i = 0; i < 100; ++i) {
				if (val % 2 == 0) {
					val = val / 2;
				}
				else {
					val = 3 * val + 1;
				}
			}

		}
	}

	return 0;
}
