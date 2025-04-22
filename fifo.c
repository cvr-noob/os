#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    pid_t pid;
    
    mkfifo("./myfifo", 0666);
    
    pid = fork();
    if (pid > 0)
    {
        int fd = open("./myfifo", O_RDWR);
        char *data = "Hello! I am data in a FIFO";
        write(fd, data, strlen(data)+1);
        printf("Parent written data into myfifo\n");
        exit(0);
    }
    else
    {
        char buff[64];
        int fd = open("./myfifo", O_RDWR);
        buff[read(fd, buff, 64)] = '\0';
        printf("myfifo has: %s\n", buff);
    }
}