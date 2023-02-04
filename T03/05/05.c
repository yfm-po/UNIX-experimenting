#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int fd = open("file", O_RDWR);
    link("file", "file2");
    link("file", "file3");

    write(fd, "Hello", 5);
    close(fd);
    
    int fd2 = open("file2", O_RDWR);
    int fd3 = open("file3", O_RDWR);
    
    char buf[5];
    read(fd2, buf, 5);
    printf("file2: %s \n", buf);
    read(fd3, buf, 5);
    printf("file3: %s \n", buf);
    
    close(fd2);
    close(fd3); 
}
