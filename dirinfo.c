#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <dirent.h>

int main() {
    //Basic Setup
    char * filename = ".";
    DIR *directory;
    struct dirent *dir_entry;
    directory = opendir(filename);


    int totalsize = 0;

    while (dir_entry = readdir(directory)) {
        if (dir_entry->d_type == DT_REG) {
            struct stat stuff; //struct to put info into.
            stat(dir_entry->d_name, &stuff);
            totalsize += (int)(stuff.st_size);
        }
    }
    printf("Total Directory Size: %d Bytes\n", totalsize);

    closedir(directory);

    directory = opendir(filename);
    printf("Directories:\n");

    while(dir_entry = readdir(directory)) {
        if (dir_entry->d_type == DT_DIR) {
            printf("\t%s\n", dir_entry->d_name);
        }
    }

    closedir(directory);
    directory = opendir(filename);
    printf("Files:\n");

    while (dir_entry = readdir(directory)) {
        if (dir_entry->d_type == DT_REG) {
            printf("\t%s\n", dir_entry->d_name);
        }
    }

    closedir(directory);

    return 0;
}
