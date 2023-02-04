#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        putchar(c);
        fflush(stdout);
        usleep(500000);
    }
}