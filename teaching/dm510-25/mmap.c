#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define FILENAME "dm510_mmap"

#define SIZE 1024

int main() {
	int file;
	int i = 0;
	file = open(FILENAME, O_CREAT | O_RDWR, 0666);
	ftruncate(file, SIZE);

	char* data = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);

	for (int i = 0; i < SIZE; ++i) {
		data[i] = ' ';
	}

	for (int j = SIZE; j >= 0; j = j - 42) {
		data[j] =  '|';
	}
	close(file);

	return 0;
}
