#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char **argv, char** env)
{
    if (argc != 2) 
    { 
        printf("usage: ./executable [file_to_execute]\n");
        exit(1);
    }

    printf("\nEnvironment variables are:\n");
    for (int i = 0; env[i] != NULL; i++) printf("%s\n", env[i]);

    execve(argv[1], &argv[1], env);
}
