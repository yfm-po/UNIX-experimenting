#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <directory>", argv[0]);
        exit(1);
    }
    
    DIR* dir = opendir(argv[1]);
    if (dir == NULL)
    {
        printf("input file is not a directory\n");
        exit(1);
    }

    struct dirent* entry;
    struct stat stats;
    while (entry = readdir(dir))
    {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) continue;

        char filepath[100];
        strcpy(filepath, argv[1]);
        strcat(filepath, "/");
        strcat(filepath, entry->d_name);
        stat(filepath, &stats);

        char timeString[20];
        strftime(timeString, 20, "%d/%m/%Y", localtime(&stats.st_mtime));
        printf("%s  ", timeString);

        char hourAndMinutesString[20];
        strftime(hourAndMinutesString, 20, "%I:%M %p", localtime(&stats.st_mtime));
        printf("%s    ", hourAndMinutesString);

        if (S_ISDIR(stats.st_mode))
        {
            printf("<DIR>  ");
        }
        else
        {
            printf("      %ld ", stats.st_size);
        }

        if (S_ISDIR(stats.st_mode))
        {
            printf("      .%s", entry->d_name);
        }
        else
        {
            printf("       %s", entry->d_name);
        }

        printf("\n");
    }
}