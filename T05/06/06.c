#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    pid_t pid;
    int i;

    pid = fork();
    if (pid < 0) 
    {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0)
    {
        printf("Child Process:");
    }
    else 
    {
        printf("Parent Process:");
    }

    for (i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s", i, argv[i]);
    }
}