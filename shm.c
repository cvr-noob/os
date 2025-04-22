#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SHM_SIZE 1024

int main()
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    char *data = shmat(shmid, NULL, 0);

    printf("Enter data: ");
    scanf(" %[^\n]", data);
    printf("Data written into shared memory.\n");

    printf("Data in the shared memory: %s\n", data);

    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
}