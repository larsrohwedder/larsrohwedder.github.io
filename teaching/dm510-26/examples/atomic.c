#include <stdio.h>
#include <unistd.h>
#include <stdatomic.h>

#define LIMIT 100000000

int main() {
	atomic_int counter = 1;

	#pragma omp parallel for
	for (int j=0; j<12; ++j) {
		while (counter < LIMIT) {
				
			int val;
		       
			val = counter;

			while (!atomic_compare_exchange_strong(&counter, &val, val+1))
				;

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
