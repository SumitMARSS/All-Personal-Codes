#include <bits/stdc++.h> 
using namespace std;

class Queue {
    int* arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {
        // Implement the Constructor
        size = 10000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront == rear)
        return true;
        else
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        //push operation
        if(rear == size)
            cout << "Queue is full" << endl;
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function

        if(qfront == rear){
            return -1;
        }
        else{
            int ans = arr[qfront];

            arr[qfront] = -1;
            qfront++;
            if(qfront==rear){
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(qfront == rear)
        return -1;
        else
        return arr[qfront];
    }
};

int main(){
    Queue q1;
    q1.enqueue(3);
    q1.enqueue(4);
    cout<<q1.front()<<endl;
}