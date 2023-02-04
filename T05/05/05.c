#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    pid = fork();

    if (pid == 0) 
    {
        printf("Child process\n");
        printf("chPID = %d\n", getpid());
        printf("chPPID = %d\n", getppid());
    }
    else if (pid > 0) 
    {
        printf("Parent process\n");
        printf("pPID = %d\n", getpid());
        printf("pPPID = %d\n", getppid());
    }
    else 
    {
        perror("fork");
    }
}