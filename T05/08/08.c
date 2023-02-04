#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int i = 0;
    pid_t pid;
    pid = fork();

    if (pid == 0)
    {
        i = 1;
        printf("Child process: i = %d and pid = %d and ppid = %d\n", i, getpid(), getppid());
    }
    else if (pid > 0)
    {
        wait(NULL);
        printf("Parent process: i = %d and pid = %d and ppid = %d\n", i, getpid(), getppid());
    }
    else
    {
        printf("Fork failed\n");
        exit(1);
    }
}