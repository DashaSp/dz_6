#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <signal.h>

int main(){
    key_t key;
    int semid;
    int a[5] = {0, 0, 0, 0, 0};
    
    key = ftok("/usr/ter/exmpl", 0);
    semid = semget(key, 5, 0666|IPC_CREAT);
    
    semctl(semid, 0, SETALL, a);
    pause();
    semctl(semid, 0, IPC_RMID, a);
}