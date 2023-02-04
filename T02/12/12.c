#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char* infile = argv[1];
    char character = argv[2][0];
    int num_bytes = atoi(argv[3]);
    int lseek_position = atoi(argv[4]);

    int fd = open(infile, O_RDWR);
    lseek(fd, lseek_position, SEEK_SET);

    char buf[num_bytes];
    memset(buf, character, num_bytes);

    write(fd, &buf, num_bytes);
    close(fd);
}