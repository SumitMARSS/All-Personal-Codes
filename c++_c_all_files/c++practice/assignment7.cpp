#include <iostream>
#include <queue>
#include <pthread.h>
#include <sys/shm.h>
#include <unistd.h>
using namespace std;

#define BUFFER_SIZE 5 // size of the bounded buffer
#define SHM_KEY 1234 // shared memory key

struct CircularQueue {
    int buffer[BUFFER_SIZE];
    int front;
    int rear;
    int count;
};

// shared memory created
int createSharedMemory() {
    int shmid = shmget(SHM_KEY, sizeof(CircularQueue), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget error");
        exit(1);
    }
    cout<<"Your shared memory is created\n";
    return shmid;
}

CircularQueue* attachSharedMemory(int shmid) {
    CircularQueue* cq = (CircularQueue*) shmat(shmid, NULL, 0);
    if (cq == (void*) -1) {
        perror("shmat error");
        exit(1);
    }
    cq->front = 0;
    cq->rear = -1;
    cq->count = 0;
    return cq;
}

void detachSharedMemory(CircularQueue* cq) {
    if (shmdt(cq) == -1) {
        perror("shmdt error");
        exit(1);
    }
    cout<<"\nYour shared memory is deatteched\n";
}

void removeSharedMemory(int shmid) {
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl error");
        exit(1);
    }
    cout<<"\nYour shared memory is removed\n";
}

// Peterson's algorithm
int turn = 0;
bool flag[2] = {false, false};
void enterCritical(int process) {
    int other = 1 - process;
    flag[process] = true;
    turn = process;
    while (flag[other] && turn == (process)) {}
}
void exitCritical(int process) {
    flag[process] = false;
}

// producer function
void* producer(void* arg) {
    CircularQueue* cq = (CircularQueue*) arg;
    int item;
    while(cq->count < BUFFER_SIZE){
        item = rand() % 10; // generate a random number
        enterCritical(0); // enter the critical section
        cq->rear = (cq->rear + 1) % BUFFER_SIZE;
            cq->buffer[cq->rear] = item;
            cq->count++;
            cout << "Producer produced item " << item << endl;
            sleep(1);
            exitCritical(0); // exit the critical section
    }
}

// consumer function
void* consumer(void* arg) {
    CircularQueue* cq = (CircularQueue*) arg;
    int item;
    while(cq->count < BUFFER_SIZE){
        enterCritical(true); // enter the critical section
        item = cq->buffer[cq->front];
            cq->front = (cq->front + 1) % BUFFER_SIZE;
            cq->count--;
            cout << "Consumer consumed item " << item << endl;
            sleep(1);
            exitCritical(true); // exit the critical section
    }
}

int main() {
    int shmid = createSharedMemory(); // create shared memory
    CircularQueue* cq = attachSharedMemory(shmid); // attach to shared memory
    // producer and consumer working 
    pid_t pid= fork();
    if(pid==-1){
        perror("Error in child creation");
    }
    else if(pid == 0){
        producer(cq);
    }
    else{
        sleep(1);
        consumer(cq);
    }
    detachSharedMemory(cq); // detach from shared memory
    removeSharedMemory(shmid); // remove shared memory
    return 0;
}
