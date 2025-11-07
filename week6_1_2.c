#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>

struct msg {
    long type;
    char text[100];
};

int main() {
    key_t key = ftok("msgfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msg m;

    if (fork() == 0) {
        m.type = 1;
        strcpy(m.text, "Hello from child");
        msgsnd(msgid, &m, sizeof(m.text), 0);
    } else {
        msgrcv(msgid, &m, sizeof(m.text), 1, 0);
        printf("Parent received: %s\n", m.text);
        msgctl(msgid, IPC_RMID, NULL);
    }
    return 0;
}
