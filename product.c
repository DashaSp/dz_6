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
    int semid, i = 1;
    key = ftok("/usr/ter/exmpl", 0);
    semid = semget(key, 5, 0666);
    
    struct sembuf d_ans = {3, -1, 0};
    struct sembuf c_ans = {2, -1, 0};
    struct sembuf ans[2] = {d_ans, c_ans};
    struct sembuf product = {4, 1, 0};
    
    while (1){
        semop(semid, ans, 2);
        printf("product - %i", i);
        fflush(stdout);
        semop(semid, &product, 1);
    }
    
    return 0;
}