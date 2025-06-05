#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    // Declare
    int fd[2];
    
    // Create pipe
    pipe(fd);

    int p = fork();
    if (p > 0)
    {  // Parent process
        close(fd[0]);  // Close read fd
        
        // Write
        const char* data = "Hello child!\n";
        write(fd[1], data, strlen(data)+1);

        // Close read fd and print
        close(fd[1]);
        printf("Parent written data into the pipe.\n");

        // Wait for child process
        wait(NULL);
    }
    else
    {  // Child process
        close(fd[1]);  // Close write fd
        
        // Read
        char data[128];
        int bytes = read(fd[0], data, 128);
        data[bytes] = '\0';

        // Print and close read fd
        printf("Child received: %s\n", data);
        close(fd[0]);
    }
}
