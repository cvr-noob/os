#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    // Declare
    int fd1, fd2;
    char* buff;

    // Open files
    fd1 = open("file1", O_RDONLY);
    fd2 = open("file2", O_WRONLY | O_CREAT, 0644);

    // Copy
    while(read(fd1, &buff, 1))
        write(fd2, &buff, 1);

    // Cleanup
    close(fd1);
    close(fd2);
    return 0;
}
