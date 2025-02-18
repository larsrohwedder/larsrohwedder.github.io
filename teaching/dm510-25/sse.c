#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


#define DIM 2048
#define IDX(I, J) (I * DIM + J)

typedef int v4si __attribute__ ((vector_size (16)));

void transpose(int* in, int* out) {
	for (int i=0; i < DIM; ++i) {
		for (int j=0; j < DIM; ++j) {
			out[IDX(i, j)] = in[IDX(j, i)];
		}
	}

}

// Compute the matrix product OUT = M1 * M2
// For various reasons this is not a smart way of multiplying matrices and serves solely as an example of a CPU heavy task
void mult(int* m1, int* m2, int* out, int* tmp) {
	transpose(m2, tmp);

	for (int i=0; i < DIM; ++i) {
		for (int j=0; j < DIM; ++j) {
			v4si vec_out = {0, 0, 0, 0};
			v4si* vec1;
			v4si* vec2;
			for (int k=0; k < DIM; k = k + 4) {
				vec1 = (v4si*) &m1[IDX(i, k)];
				vec2 = (v4si*) &tmp[IDX(j, k)];
				vec_out += (*vec1) * (*vec2);
			}
			int* int_out = (int*) &vec_out;
			out[IDX(i, j)] = int_out[0] + int_out[1] + int_out[2] + int_out[3];
		}
	}

}

int main() {
	int* a;
	int* b;
       	int* c;
       	int* d;
	int* tmp;

	a = malloc(DIM * DIM * sizeof(int));
	b = malloc(DIM * DIM * sizeof(int));
	c = malloc(DIM * DIM * sizeof(int));
	d = malloc(DIM * DIM * sizeof(int));
	tmp = malloc(DIM * DIM * sizeof(int));

	// Initialization with non-sense values
	for (int i=0; i < DIM; ++i) {
		for (int j=0; j < DIM; ++j) {
			a[IDX(i, j)] = i * j;
			b[IDX(i, j)] = i + j;
		}
	}

	mult(a, a, c, tmp);
	/*
	for (int i = 0; i < DIM; ++i) {
		for (int j = 0; j < DIM; ++j) {
			printf("%d ", c[IDX(i, j)]);
		}
		printf("\n");
	}
	*/

	mult(a, b, d, tmp);

	return 0;
}
