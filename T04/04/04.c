#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char login[100];
    char passwd[100];
    printf("Login: ");
    fgets(login, sizeof(login), stdin);

    printf("Password?: ");
    struct termios term;
    tcgetattr(fileno(stdin), &term);
    
    term.c_lflag &= ~ECHO;

    tcsetattr(fileno(stdin), 0, &term);
    fgets(passwd, sizeof(passwd), stdin);

    term.c_lflag |= ECHO;

    tcsetattr(fileno(stdin), 0, &term);
    printf("\n\nYour password is: %s\n", passwd);
}