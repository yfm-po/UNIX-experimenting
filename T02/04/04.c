#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("\nOpening the given file => \n");
    int infile = open("infile", O_RDONLY);

    long infileLength = lseek(infile, 0, SEEK_END);
    lseek(infile, 0, SEEK_SET);

    printf("Allocating buffer and reading content into it with 3 more bytes size => \n");
    char buffer[infileLength];
    int reader = read(infile, &buffer, infileLength + 3);

    printf("return value of read(): %d\n", reader);
    printf("Content of the buffer is => %s\n", &buffer);
    
    printf("errno: %d\n", errno);
    perror("perror(): ");
    printf("strerror(): %s", strerror(errno));

    close(infile);
}

