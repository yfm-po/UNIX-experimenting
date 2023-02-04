#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

int main() 
{
	struct termios tty;
	char buffer[100];

	tcgetattr(fileno(stdin), &tty);
	tty.c_lflag &= ~ICANON;
	tty.c_lflag &= ~ECHO;
	tcsetattr(fileno(stdin), TCSANOW, &tty);

	printf("Enter string: ");
	scanf("%s", buffer);

	for (int i = 0; i < strlen(buffer); i++) 
    {
		putchar(buffer[i]);
		fflush(stdout);
		sleep(1);
	}
	putchar('\n');
}