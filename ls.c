#include <stdio.h>
#include <dirent.h>

int main()
{
    char dirname[10];
    DIR *dir;
    struct dirent *entry;

    printf("Enter directory name: ");
    scanf("%s", dirname);

    dir = opendir(dirname);
    while (entry = readdir(dir)) {
        char* name = entry->d_name;
        if (name[0] != '.')
            printf("%s\n", entry->d_name);
    }

    return 0;
}