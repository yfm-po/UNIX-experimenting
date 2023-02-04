#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[]) 
{
	if (argc != 2) 
    {
		fprintf(stderr, "Usage: %s <character>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (strlen(argv[1]) != 1) 
    {
		fprintf(stderr, "Argument must be a single character.\n");
		exit(EXIT_FAILURE);
	}

	if (ioctl(STDIN_FILENO, TIOCSTI, argv[1]) == -1) 
    {
		perror("ioctl()");
		exit(EXIT_FAILURE);
	}
}