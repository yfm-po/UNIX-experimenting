#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd1, fd2;
    char buf[10];

    fd1 = open("file", O_RDWR);
    fd2 = dup(fd1);

    read(fd1, buf, 5);
    printf("fd1: %s\n", buf);

    read(fd2, buf, 5);
    printf("fd2: %s\n", buf);

    close(fd1);
    close(fd2);
}
