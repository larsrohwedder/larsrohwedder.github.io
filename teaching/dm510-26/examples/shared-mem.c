#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define BUFLEN 10

struct shared_mem_t {
	int in;
	int out;
	int buffer[BUFLEN];
};

typedef struct shared_mem_t shared_mem;


int main() {
	int fd;
	int i = 0;

	shared_mem* shared = mmap(0, sizeof(shared_mem), PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (shared == MAP_FAILED) {
		printf("allocation failed");
		return -1;
	}

	if (fork() == 0) {
		printf("child\n");

		while (1) {
			sleep(1);
			i++;
			printf("produced %d\n", i);

			while (((shared->in + 1) % BUFLEN) == shared->out)
				;
			shared->buffer[shared->in] = i;
			shared->in = (shared->in + 1) % BUFLEN;
		}
	} else {
		printf("parent\n");
		
		while (1) {
			while (shared->in == shared->out)
				;
			i = shared->buffer[shared->out];
			shared->out = (shared->out + 1) % BUFLEN;

			printf("consumed %d\n", i);
		}
	}
	munmap(shared, sizeof(shared_mem));

	return 0;

}
