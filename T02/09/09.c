#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    int infile = open("infile", O_RDONLY);

    int lseek1 = lseek(infile, 10, SEEK_CUR);
    printf("lseek From Actual Position 10 bytes: %d\n", lseek1);
    printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s\n", strerror(errno));

    int lseek2 = lseek(infile, -10, SEEK_CUR);
    printf("lseek From Actual Position - 10 bytes: %d\n", lseek2);
    printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s\n", strerror(errno));

    int lseek3 = lseek(infile, 10, SEEK_SET);
    printf("lseek From Beginning 10 bytes: %d\n", lseek3);
    printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s\n", strerror(errno));

    int lseek4 = lseek(infile, -10, SEEK_SET);
    printf("lseek From Beginning - 10 bytes: %d\n", lseek4);
    printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s\n", strerror(errno));

    int lseek5 = lseek(infile, 10, SEEK_END);
    printf("lseek From End 10 bytes: %d\n", lseek5);
    printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s\n", strerror(errno));

    int lseek6 = lseek(infile, -10, SEEK_END);
    printf("lseek From End - 10 bytes: %d\n", lseek6);
    printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s\n", strerror(errno));


    close(infile);
}