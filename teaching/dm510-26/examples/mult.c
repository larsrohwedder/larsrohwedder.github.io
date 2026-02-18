#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define DIM 2048
#define IDX(I, J) (I * DIM + J)


void transpose(int* in, int* out) {
	for (int i=0; i < DIM; ++i) {
		for (int j=0; j < DIM; ++j) {
			out[IDX(i, j)] = in[IDX(j, i)];
		}
	}

}

// Compute the matrix product out = m1 * m2
// For various reasons this is not a smart way of multiplying matrices and serves solely as an example of a CPU heavy task
void mult(int* m1, int* m2, int* out, int* tmp) {
	transpose(m2, tmp);

#pragma omp parallel for
	for (int i=0; i < DIM; ++i) {
		for (int j=0; j < DIM; ++j) {
			out[IDX(i, j)] = 0;
			for (int k=0; k < DIM; ++k) {
				// out[IDX(i, j)] += m1[IDX(i, k)] * m2[IDX(k, j)];
				// work with transposed matrix for more locality (fewer cache misses)
				out[IDX(i, j)] += m1[IDX(i, k)] * tmp[IDX(j, k)];
			}
		}
	}

}

int main() {
	int* a;
	int* b;
    	int* c;
	int* tmp;

	a = malloc(DIM * DIM * sizeof(int));
	b = malloc(DIM * DIM * sizeof(int));
	c = malloc(DIM * DIM * sizeof(int));
	tmp = malloc(DIM * DIM * sizeof(int));

	// Initialization with non-sense values
	for (int i=0; i < DIM; ++i) {
		for (int j=0; j < DIM; ++j) {
			a[IDX(i, j)] = i * j;
			b[IDX(i, j)] = i + j;
		}
	}

	mult(a, b, c, tmp);

	return 0;
}
