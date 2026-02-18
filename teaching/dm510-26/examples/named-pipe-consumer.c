#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define PIPE "dm510_fifo"

int main() {
	char i;
	int file = open(PIPE, O_RDONLY);
	if (!file) {
		printf("failed to open pipe");
		return -1;
	}

	while ( 1 ) {
		int num = read(file, &i, 1);
		if (num > 0) {
			printf("read %d\n", (int)i);
		}
	}
	return 0;
}
