#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    int infile = open("infile", O_RDONLY);
    printf("Putting the cursor 1000000 after the last byte of the file => \n");
    long lseek1 = lseek(infile, 1000000, SEEK_SET);
    printf("return value of this lseek: %ld\n", lseek1);
    char buffer[10]; 
    int read1 = read(infile, &buffer, 10);
    printf("return value of this read: %d\n", read1);
    printf("What's in the buffer? (string form) : %s\n", &buffer);
    printf("What's in the buffer? (hex form) : %x\n", &buffer);
    close(infile);

    int infile2 = open("infile2", O_RDONLY);
    printf("Putting the cursor right after the last byte of the file => \n");
    int lseek2 = lseek(infile2, 0, SEEK_SET);
    printf("return value of this lseek: %d\n", lseek2);
    char buffer2[10]; 
    int read2 = read(infile2, &buffer2, 10);
    printf("return value of this read: %d\n", read2);
    printf("What's in the buffer? (string form) : %s\n", &buffer2);
    printf("What's in the buffer? (hex form) : %x\n", &buffer2);
    close(infile2);

    int infile3 = open("infile3", O_RDONLY);
    printf("The cursor at the original position => \n");
    char buffer3[10]; 
    int read3 = read(infile3, &buffer3, 10);
    printf("return value of this read: %d\n", read3);
    printf("What's in the buffer? (string form) : %s\n", &buffer3);
    printf("What's in the buffer? (hex form) : %x\n", &buffer3);
    close(infile3);
}