#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct message
{
    long type;
    char text[256];
} message;

int main()
{
    FILE *fp = fopen("./msgq", "w");
    fclose(fp);

    key_t key = ftok("./msgq", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    message msg = {1, "Hello"};
    msgsnd(msgid, &msg, sizeof(msg.text), 0);
    printf("Message sent.\n");

    return 0;
}