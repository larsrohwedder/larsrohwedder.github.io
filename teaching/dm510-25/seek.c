#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


#define FILENAME "dm510_seek"

#define SIZE 1024

int main() {
	int file;
	int i = 0;
	file = open(FILENAME, O_CREAT | O_RDWR, 0666);

	for (int i = 0; i < SIZE; ++i) {
		write(file, " ", 1);
	}

	for (int j = SIZE; j >= 0; j = j - 42) {
		lseek(file, j, SEEK_SET);
		write(file, "|", 1);
	}
	close(file);

	return 0;
}
