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
    key = ftok("/usr/ter/exmpl", 0);
    semid = semget(key, 5, 0666);
    
    struct sembuf A_ans = {0, -1, 0};
    struct sembuf B_ans = {1, -1, 0};
    struct sembuf ans[2] = {A_ans, B_ans};
    struct sembuf d = {3, 1, 0};
    
    while (1){
        semop(semid, ans, 2);
        semop(semid, &d, 1);
    }
    return 0;
}