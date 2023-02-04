#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        printf("usage: ./executable [file] [data]\n");
        exit(1);
    }
    int file = open(argv[1], O_WRONLY | O_CREAT);
    char* data = (char*)argv[2];
    write(file, data, strlen(data));
    close(file);
}


