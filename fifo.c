#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/stat.h>

int main()
{
    // Make fifo
    mkfifo("./myfifo", 0644);

    int pid = fork();
    if (pid > 0)
    {  // Parent process
        // Open fifo
        int fd = open("./myfifo", O_WRONLY);
        
        // Write
        char *data = "Hello child!";
        write(fd, data, strlen(data)+1);
        
        // Cleanup
        close(fd);
        wait(NULL);
        unlink("./myfifo");
    }
    else
    {  // Child process
        // Open fifo
        int fd = open("./myfifo", O_RDONLY);

        // Read
        char data[128];
        int bytes = read(fd, data, 128);
        data[bytes] = '\0';

        // Print
        printf("Child received: %s\n", data);

        // Cleanup
        close(fd);
    }
}
