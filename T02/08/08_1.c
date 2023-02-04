#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() 
{ 
    char buffer[1];

    int infile = open("infile", O_RDONLY);
    int outfile = open("outfile", O_WRONLY);

    time_t start = time(NULL);

    while(read(infile, &buffer, 1) > 0)
    {
        write(outfile, &buffer, 1);
    }

    time_t end = time(NULL);
    printf("Time taken for copying 5megabytes from infile to outfile 1 byte at a time: %ld seconds\n", end - start);

    close(infile);
    close(outfile);
}