#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <linux/limits.h>

#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void print_permissions(mode_t mode);

int main(int argc, char **argv)
{
    const char *dirname = argv[1];
    DIR *dir = opendir(dirname);
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL)
    {
        char path[PATH_MAX];
        snprintf(path, PATH_MAX, "%s/%s", dirname, entry->d_name);

        struct stat file_stat;
        stat(path, &file_stat);

        print_permissions(file_stat.st_mode); // 1. Permissions

        struct passwd *user_info = getpwuid(file_stat.st_uid);
        printf("\t%s", user_info->pw_name); // 2. Username

        struct group *group_info = getgrgid(file_stat.st_gid);
        printf("\t%s", group_info->gr_name); // 3. Group name

        printf("\t%ld", file_stat.st_size); // 4. Size

        struct tm *time_info = localtime(&file_stat.st_mtime);
        char time_str[80];
        strftime(time_str, sizeof(time_str), "%b %d %H:%M", time_info);
        printf("\t%s", time_str); // 5. Modification time

        printf("\t%s\n", entry->d_name); // 6. File name
    }

    return 0;
}

void print_permissions(mode_t mode)
{
    printf(S_ISDIR(mode) ? "d" : "-");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
}