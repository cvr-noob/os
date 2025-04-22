#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    char buf;
    int fd1, fd2;

    fd1 = open("file1", O_RDONLY);
    fd2 = open("file2", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    while (read(fd1, &buf, 1))
        write(fd2, &buf, 1);

    printf("Copied!\n");

    close(fd1);
    close(fd2);

    return 0;
}