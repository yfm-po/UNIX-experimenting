#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    if (argc != 3) 
    {
        printf("Usage: %s <file> <link> or %s <link> <file>\n", argv[0], argv[0]);
        exit(1);
    }

    struct stat st;
    if (stat(argv[1], &st) == -1) 
    {
        perror("stat");
        exit(1);
    }

    if (S_ISDIR(st.st_mode)) 
    {
        printf("Cannot create a link to a directory.\n");
        exit(1);
    }

    if (symlink(argv[1], argv[2]) == -1) 
    {
        perror("symlink");
        exit(1);
    }
}