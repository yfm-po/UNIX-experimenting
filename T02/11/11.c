#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    int infile = open("infile", O_RDWR);
    lseek(infile, 9, SEEK_SET);
    char buf[3] = "AAA";
    write(infile, buf, 3);
    close(infile);
}

