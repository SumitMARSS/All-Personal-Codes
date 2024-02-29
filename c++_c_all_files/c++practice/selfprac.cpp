/*
//lec -21_22 page 12 execution and why not running
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_SIZE  1024

int main(){
    int pfd[2];//an array use to store file discripter for pipes
    int pid;
    char buffer[MAX_SIZE];
    int checkread;
	//pipe(pfd) is used to create the pipe with pfd[0] as read and pfd[1] as write
    if(pipe(pfd)==-1){
        perror("Error in file creation\n");
        exit(1);
    }
    if((pid=fork())<0){
        perror("Error in child creation\n");
        exit(2);
    }
    if(pid==0){
        //wait(NULL);
        close(pfd[1]);//closing the write option
        //printf("You are working on child process\n");
        while(checkread=read(pfd[0],buffer,MAX_SIZE)!=0){
            printf("Child read that buffer is %s",buffer);
        }
        close(pfd[0]);
    }
    else{
        close(pfd[0]);//closing the read option
        //printf("You are working on parent process\n");
        strcpy(buffer,"I am parent process\n");
        write(pfd[1],buffer,strlen(buffer)+1);
        close(pfd[1]);//closing the writing option from parent
    }
}
*/
//page 13
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_SIZE  1024

int main(){
    int pfd[2];
    int pid;
    char buffer[MAX_SIZE];
    //int checkread;
    if(pipe(pfd)==-1){
        perror("Error in file creation\n");
        exit(1);
    }
    if((pid=fork())<0){
        perror("Error in child creation\n");
        exit(2);
    }
    if(pid==0){
        printf("Child is writing in pipe\n");
        strcpy(buffer,"HIII!! I am testing write operation\n");
        write(pfd[1],buffer,strlen(buffer)+1);
        printf("Child:exiting\n");
        exit(0);
    }
    else{
        printf("Parent is reading from pipe\n");
        read(pfd[0],buffer,MAX_SIZE);
        printf("Parent read: %s\n",buffer);
        wait(NULL);
        close(pfd[0]);
        close(pfd[1]);
        exit(0);
    }
}

*/