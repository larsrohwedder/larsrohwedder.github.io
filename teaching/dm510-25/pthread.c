#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define DIM 2048
#define IDX(I, J) (I * DIM + J)

typedef struct thread_params_t {
	int* m1;
	int* m2;
	int* out;
	int* tmp;
} thread_params;

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
	// We are transposing M2 so that we can access the entries sequentially
	transpose(m2, tmp);

	for (int i=0; i < DIM; ++i) {
		for (int j=0; j < DIM; ++j) {
			out[IDX(i, j)] = 0;
			for (int k=0; k < DIM; ++k) {
				out[IDX(i, j)] += m1[IDX(i, k)] * tmp[IDX(j, k)];
			}
		}
	}

}

void* runner(void *param) {
	thread_params* p = (thread_params*)param;
	mult(p->m1, p->m2, p->out, p->tmp);
}

int main() {
	int* a;
	int* b;
	int* c;
	int* d;
	int* tmp1;
	int* tmp2;

	a = malloc(DIM * DIM * sizeof(int));
	b = malloc(DIM * DIM * sizeof(int));
	c = malloc(DIM * DIM * sizeof(int));
	d = malloc(DIM * DIM * sizeof(int));
	tmp1 = malloc(DIM * DIM * sizeof(int));
	tmp2 = malloc(DIM * DIM * sizeof(int));

	// Initialization with non-sense values
	for (int i=0; i < DIM; ++i) {
		for (int j=0; j < DIM; ++j) {
			a[IDX(i, j)] = i * j;
			b[IDX(i, j)] = i + j;
		}
	}

	pthread_t tid1;
	pthread_t tid2;
	pthread_attr_t attr;

	pthread_attr_init(&attr);

	thread_params p1;
	thread_params p2;

	p1.m1 = a;
	p1.m2 = a;
	p1.out = c;
	p1.tmp = tmp1;
	pthread_create(&tid1, &attr, runner, &p1);

	p2.m1 = a;
	p2.m2 = b;
	p2.out = d;
	p2.tmp = tmp2;
	pthread_create(&tid2, &attr, runner, &p2);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	return 0;
}
