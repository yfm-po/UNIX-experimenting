#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char** argv, char** env)
{
    printf("\nCommand line arguments:\n");
    for (int i = 0; i < argc; i++) printf("%s\n", argv[i]);
 
    printf("\nEnvironment variables are:\n");
    for (int i = 0; env[i] != NULL; i++) printf("%s\n", env[i]);
}