#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void print_perms(mode_t);

int main(int argc, char** argv)
{
    // Open dir
    DIR *dir = opendir(".");
    
    // Read dir
    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL)
    {
        // Get stats
        struct stat file_stat;
        stat(ent->d_name, &file_stat);
        
        // Print permissions
        print_perms(file_stat.st_mode);

        // Print link count
        printf("\t%d", file_stat.st_nlink);
        
        // Print username
        struct passwd *usr_inf = getpwuid(file_stat.st_uid);
        printf("\t%s", usr_inf->pw_name);

        // Print group name
        struct group *grp_inf = getgrgid(file_stat.st_gid);
        printf("\t%s", grp_inf->gr_name);

        // Print size
        printf("\t%d", file_stat.st_size);

        // Print last modified time
        struct tm *tm_inf = localtime(&file_stat.st_mtime);
        char time[100];
        strftime(time, sizeof(time), "%b %d %H:%M", tm_inf);
        printf("\t%s", time);

        // Print name
        printf("\t%s\n", ent->d_name);
    }
}

void print_perms(mode_t mode)
{
    int perms[] = {
        S_IRUSR, S_IWUSR, S_IXUSR,
        S_IRGRP, S_IWGRP, S_IXGRP,
        S_IROTH, S_IWOTH, S_IXOTH,
    };
    const char *rwx = "rwx";

    putchar(S_ISDIR(mode) ? 'd' : '-');
    for (int i=0; i<9; i++)
        putchar(mode & perms[i] ? rwx[i % 3] : '-');
}
