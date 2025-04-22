#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
    const char *mode_str = argv[1];
    const char *file = argv[2];

    mode_t mode = strtol(mode_str, NULL, 8);
    chmod(file, mode);
    printf("File permissions changed successfully.\n");

    return 0;
}