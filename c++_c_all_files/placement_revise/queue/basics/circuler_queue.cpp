#include <bits/stdc++.h> 
class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        //1. check if queue is full or not
        if((front == 0 && rear == (size-1)) || (rear == (front-1)%(size-1))){
            return false;
        }
        //2. if first element is inserted
        else if(front == -1){
            front = 0;
            rear = 0;
            arr[rear] = value;
        }
        //3. if rear is at end and front is in mid
        else if(rear == (size-1) && front != 0){
            rear = 0;
            arr[rear] = value;
        }
        //4. normal case
        else{
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        //1. check for empty case
        if(front == -1 && rear == -1) {
            return -1;
        }
        int ans = arr[front];
        //if having only 1 element
        if(rear == front){
            rear = -1;
            front = -1;
        }
        else if(front == (size-1)){
            front = 0;
        }
        else{
            front++;
        }
        return ans;
    }
};