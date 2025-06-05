#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
    // Declare
    char* mode_str = argv[1];
    char* file = argv[2];

    // Chmod
    chmod(file, strtol(mode_str, NULL, 8));

    return 0;
}
