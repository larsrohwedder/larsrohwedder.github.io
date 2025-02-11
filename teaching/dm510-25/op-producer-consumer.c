#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int my_pipe[2];
	if (pipe(my_pipe) == -1) {
		printf("failed to create pipe");
		return -1;
	}
	char i = 0;

	if (fork() == 0) {

		printf("parent\n");
		while ( 1 ) {
			int num = read(my_pipe[0], &i, 1);
			if (num > 0) {
				printf("read %d\n", (int)i);
			}
		}

	}
	else {

		printf("child\n");
		while ( 1 ) {
			i++;
			write(my_pipe[1], &i, 1);
			printf("write %d\n", (int)i);
			sleep(1);
		}

	}

	return 0;
}
