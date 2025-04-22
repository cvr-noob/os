#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFF_SIZE 1024

int main()
{
    int fd[2];
    pid_t p;

    pipe(fd);

    p = fork();
    if (p > 0)
    {
        close(fd[0]);
        printf("Parent sending data to child...\n");
        
        const char *data = "Hello from parent!";
        write(fd[1], data, strlen(data) + 1);

        close(fd[1]);
        wait(NULL);
    }
    else
    {
        close(fd[1]);
        char buff[BUFF_SIZE];
        printf("Child receiving data from parent...\n");

        buff[read(fd[0], buff, BUFF_SIZE)] = '\0';
        
        printf("Data received: %s\n", buff);
        close(fd[0]);
    }

    return 0;
}