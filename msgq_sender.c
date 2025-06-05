#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct message
{
    long type;
    char text[128];
} message;

int main()
{
    // Generate Key
    int key = ftok("./msgq", 65);
    
    // Generate message queue
    int msgqid = msgget(key, 0644 | IPC_CREAT);

    // Create message
    message msg = {1, "Hello world"};
    
    // Send message to message queue
    msgsnd(msgqid, &msg, sizeof(msg.text), 0);
    printf("Message sent to the message queue.\n");
}
