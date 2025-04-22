#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    
    mkfifo("./myfifo", 0666);
    
    pid = fork();
    if (pid > 0)
    {
        int fd = open("./myfifo", O_WRONLY);
        char *data = "Hello! I am data in a FIFO";
        write(fd, data, strlen(data)+1);
        printf("Parent written data into myfifo\n");
        
        close(fd);
        wait(NULL);
        unlink("myfifo");
    }
    else
    {
        char buff[64];
        int fd = open("./myfifo", O_RDONLY);
        buff[read(fd, buff, 64)] = '\0';
        printf("myfifo has: %s\n", buff);

        close(fd);
    }
}