#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct message
{
    long type;
    char text[256];
} message;

int main()
{
    key_t key = ftok("./msgq", 65);
    int msgid = msgget(key, 0);

    message msg;
    msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);

    printf("msgq has: %s\n", msg.text);

    return 0;
}