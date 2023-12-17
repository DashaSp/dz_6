#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <sys/msg.h>
#include <signal.h>

int main(){
    key_t key;
    int semid;
    key = ftok("/usr/ter/exmpl", 0);
    semid = semget(key, 5, 0666);
    struct sembuf A = {0, 1, 0};
    
    while(1){
        sleep(2);
        semop(semid, &A, 1);
    }
    return 0;
}