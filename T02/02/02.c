#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
	printf("\nCase when opening a non existing file with O_CREAT | O_EXCL => \n");
	int newlyCreatedFileThatDidntExistBefore = open("newlyCreatedFile", O_CREAT | O_EXCL);
	printf("New file descriptor => %d\n", newlyCreatedFileThatDidntExistBefore);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));

	printf("\nCase when opening an already existing file with O_CREAT | O_EXCL => \n");
	int alreadyExistingFile = open("existingFile", O_CREAT | O_EXCL);
	printf("New file descriptor => %d\n", alreadyExistingFile);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));

	close(newlyCreatedFileThatDidntExistBefore);
	close(alreadyExistingFile);

	printf("\nCase when opening a non existing file without O_CREAT | O_EXCL => \n");
	int newFile = open("newFile", O_RDWR);
	printf("New file descriptor => %d\n", newFile);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));

	printf("\nCase when opening an already existing file without O_CREAT | O_EXCL => \n");
	int _alreadyExistingFile = open("_existingFile", O_RDWR);
	printf("New file descriptor => %d\n", _alreadyExistingFile);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));
	printf("\n");

	close(newFile);
	close(_alreadyExistingFile);
}

