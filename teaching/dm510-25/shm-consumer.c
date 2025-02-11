#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define SHM "dm510_shm"

#define BUFLEN 10

struct shared_mem_t {
	int in;
	int out;
	int buffer[BUFLEN];
};

typedef struct shared_mem_t shared_mem;

int main() {
	int file;
	int i;
	file = shm_open(SHM, O_CREAT | O_RDWR, 0666);

	shared_mem* shared = mmap(0, sizeof(shared_mem), PROT_WRITE, MAP_SHARED, file, 0);

	while ( 1 ) {
		while (shared->in == shared->out)
			;
		i = shared->buffer[shared->out];
		shared->out = (shared->out + 1) % BUFLEN;

		printf("consumed %d\n", i);
	}

	return 0;
}
