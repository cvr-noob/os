#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 128

int main()
{
    // Generate key
    int key = ftok("shmfile", 65);

    // Get Shared Memory
    int shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT);

    // Attach Shared Memory
    char *data = shmat(shmid, NULL, 0);

    // User Input
    printf("Enter data into the shared memory: ");
    scanf("%[^\n]", data);

    // Print
    printf("Data inside shared memory: ", data);

    // Cleanup
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
}
