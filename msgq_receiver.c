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
    
    // Get message queue
    int msgid = msgget(key, 0);

    // Receive message
    message msg;
    msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);

    // Print
    printf("Received: %s\n", msg.text);
}
