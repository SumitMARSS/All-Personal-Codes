#include <stdio.h>
#include <sys/types.h>

#define n 10

void parentprocess(void){
    for (int i = 0; i < n; i++)
    {
        printf("Parent process %d\n",i);
    }
    printf("Parent process finished\n");
}

void childprocess(void){
    for (int i = 0; i < n; i++)
    {
        printf("Child process %d\n",i);
    }
    printf("Child process finished\n");
}

int main(){
    pid_t pid;
    int status;
    pid = fork();
    if (pid<0)
    {
        printf("Error in fork creation\n");
    }
    else if (pid==0)
    {
        //sleep(2);
        getpid();
        getppid();
        printf("Child id is %d\n",getpid());
        printf("Child's parent id is %d\n",getppid());
        childprocess();
    }
    else
    {
        //wait(&status);
        //exit(0);
        sleep(5000);
        getpid();
        printf("Parent id is %d\n",getpid());
        parentprocess();
    }
    
}