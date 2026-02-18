#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define PIPE "dm510_fifo"

int main() {
	char i = 0;
	int file = open(PIPE, O_WRONLY);
	if (!file) {
		printf("failed to open pipe");
		return -1;
	}

	while ( 1 ) {
		i++;
		write(file, &i, 1);
		printf("write %d\n", (int)i);
		sleep(1);
	}
	return 0;
}
