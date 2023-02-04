#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main() 
{ 
    char buffer[1024];

    while (read(STDIN_FILENO, &buffer, 1024) > 0)
    {
        write(STDOUT_FILENO, &buffer, 1024);
    }
}