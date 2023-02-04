#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
	printf("\nCase when opening a non existing file with O_CREAT and mode 0777 => \n");
	int newlyCreatedFileThatDidntExistBefore = open("newlyCreatedFile1", O_CREAT, 0777);
	printf("New file descriptor => %d\n", newlyCreatedFileThatDidntExistBefore);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));
    printf("\n");

	printf("\nCase when opening an already existing file with O_CREAT and mode 0777 => \n");
	int alreadyExistingFile = open("existingFile", O_CREAT, 0777);
	printf("New file descriptor => %d\n", alreadyExistingFile);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));
    printf("\n");

	close(newlyCreatedFileThatDidntExistBefore);
	close(alreadyExistingFile);

	printf("\nCase when opening a non existing file without O_CREAT and mode 0777 => \n");
	int newFile = open("newFile1", O_RDWR, 0777);
	printf("New file descriptor => %d\n", newFile);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));
    printf("\n");

	printf("\nCase when opening an already existing file without O_CREAT and mode 0777 => \n");
	int _alreadyExistingFile = open("_existingFile", O_RDWR, 0777);
	printf("New file descriptor => %d\n", _alreadyExistingFile);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));
	printf("\n");

    close(newFile);
	close(_alreadyExistingFile);



    printf("\nCase when opening a non existing file with O_CREAT and mode 0666 => \n");
	int newlyCreatedFileThatDidntExistBefore2 = open("newlyCreatedFile2", O_CREAT, 0666);
	printf("New file descriptor => %d\n", newlyCreatedFileThatDidntExistBefore2);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));
    printf("\n");

	printf("\nCase when opening an already existing file with O_CREAT and mode 0666 => \n");
	int alreadyExistingFile2 = open("existingFile", O_CREAT, 0666);
	printf("New file descriptor => %d\n", alreadyExistingFile2);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));
    printf("\n");

	close(newlyCreatedFileThatDidntExistBefore2);
	close(alreadyExistingFile2);

	printf("\nCase when opening a non existing file without O_CREAT and mode 0666 => \n");
	int newFile2 = open("newFile2", O_RDWR, 0666);
	printf("New file descriptor => %d\n", newFile2);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));
    printf("\n");

	printf("\nCase when opening an already existing file without O_CREAT and mode 0666 => \n");
	int _alreadyExistingFile2 = open("_existingFile", O_RDWR, 0666);
	printf("New file descriptor => %d\n", _alreadyExistingFile2);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));
	printf("\n");

	close(newFile2);
	close(_alreadyExistingFile2);



    printf("\nCase when opening a non existing file with O_CREAT and mode 0775 => \n");
	int newlyCreatedFileThatDidntExistBefore3 = open("newlyCreatedFile3", O_CREAT, 0775);
	printf("New file descriptor => %d\n", newlyCreatedFileThatDidntExistBefore3);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));
    printf("\n");

	printf("\nCase when opening an already existing file with O_CREAT and mode 0775 => \n");
	int alreadyExistingFile3 = open("existingFile", O_CREAT, 0775);
	printf("New file descriptor => %d\n", alreadyExistingFile3);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));
    printf("\n");

	close(newlyCreatedFileThatDidntExistBefore3);
	close(alreadyExistingFile3);

	printf("\nCase when opening a non existing file without O_CREAT and mode 0775 => \n");
	int newFile3 = open("newFile3", O_RDWR, 0775);
	printf("New file descriptor => %d\n", newFile3);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));
    printf("\n");

	printf("\nCase when opening an already existing file without O_CREAT and mode 0775 => \n");
	int _alreadyExistingFile3 = open("_existingFile", O_RDWR, 0775);
	printf("New file descriptor => %d\n", _alreadyExistingFile3);
	printf("errno: %d\n", errno);
	perror("perror(): ");
	printf("strerror(): %s", strerror(errno));
	printf("\n");

	close(newFile3);
	close(_alreadyExistingFile3);
}

