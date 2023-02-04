#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("file", O_RDONLY);
    int fdCurrentCursorPosition = lseek(fd, 10, SEEK_SET);
    printf("Current Position of fd: %d\n", fdCurrentCursorPosition);

    int fd2 = dup(fd);
    int fd2CurrentCursorPosition = lseek(fd2, 0, SEEK_CUR);
    printf("Current Position of fd2: %d\n", fd2CurrentCursorPosition);
    printf("Cursor position is remembered in the alternate channel\n", fdCurrentCursorPosition == fd2CurrentCursorPosition ? "" : "not");
    close(fd);  
}