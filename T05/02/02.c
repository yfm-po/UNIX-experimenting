#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

int main(int argc, char *argv[], char *envp[]) 
{ 
    if (argc != 2) 
    { 
        printf("usage: ./executable [file_to_execute]\n");
        exit(1);
    } 

    execve(argv[1], &argv[1], envp); 
    exit(1); 
}