#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file>", argv[0]);
        exit(1);
    }
    
    int fd = open(argv[1], O_RDONLY);
    struct stat st;
    fstat(fd, &st);
    printf( (S_ISDIR(st.st_mode)) ? "is a directory\n" : "is not a directory\n");
}
