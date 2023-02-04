#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{ 
    struct termios old_tio, new_tio;
    unsigned char c;
    int k = 1, rv;

    tcgetattr(STDIN_FILENO,&old_tio);
    new_tio =o ld_tio;
    new_tio.c_lflag &=(~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    c = 0;
    while(c != '\n')
    {
        printf(" %d \r",c);
        usleep((useconds_t) 500000);
        c = getchar();
        if (c>='0' && c <='9') k = c - 0x30;
    }
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
}