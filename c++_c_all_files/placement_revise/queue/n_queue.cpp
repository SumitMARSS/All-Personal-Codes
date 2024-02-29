#include<iostream>
using namespace std;

class kQueue {

    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freeSpot;
        int *next;

    public:
        kQueue(int n, int k) {
            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];
            for(int i=0; i<k; i++) {
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for(int i=0; i<n; i++) {
                next[i] = i+1;
            }
            next[n-1] = -1;
            arr = new int[n];
            freeSpot = 0;
        }    

        void enqueue(int data, int qn) {

            //overflow
            if( freeSpot == -1) {
                cout << "No Empty space is present" << endl;
                return;
            }

            //find first free index
            int index = freeSpot;

            //update freespot
            freeSpot = next[index];

            //check whther first element
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }
            else{
                //link new element to the prev element
                next[rear[qn-1]] = index;
            }

            //update next
            next[index] = -1;

            //update rear
            rear[qn-1] = index;

            //push element
            arr[index] = data;
        }

        int dequeue(int qn) {
            //underflow 
            if(front[qn-1] == -1)
            {
                cout << "Queue UnderFlow " << endl;
                return -1;
            }

            //find index to pop
            int index = front[qn-1];

            //front ko aage badhao
            front[qn-1] = next[index];

            //freeSlots ko manage karo
            next[index] = freeSpot;
            freeSpot = index;
            return arr[index];
        }

};

int main() {

    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// class kqueue{
//     public:
//     int size;
//     int k;
//     int *front;
//     int *rear;
//     int *arr;
//     int freespot;
//     int *next;

//     kqueue(int s, int k_s){
//         this->size = s;
//         this->k = k_s;
//         front = new int [k];
//         rear = new int [k]; 
//         for (int i = 0; i < k; i++)
//         {
//             front[i] = -1;
//             rear[i] = -1;
//         }
//         arr = new int [size];
//         //all free spots filled in next
//         next = new int [size];
//         for (int  i = 0; i < size; i++)
//         {
//             next[i] = i+1;
//         }
//         next[size-1] = -1;
//         //freespot
//         freespot = 0;
//     }
//     void enqueue(int val,int qn){
//         //check if queue is full
//         if (freespot == -1)
//         {
//             cout << "No Empty space is present" << endl;
//             return;
//         }

//         //get free spot
//         int index = freespot;

//         //update freespot
//         freespot = next[index];

//         //check whther first element and push in queue
//         if (front[qn-1] == -1)
//         {
//             front[qn-1] = index;//0 based indexing
//         }
//         else
//         {
//             next[rear[qn-1]] = index;// we can keep track of the kth queue element
//         }
//         //update next
//         next[index] = -1;
//         //update rear
//         rear[qn-1] = index;
//         //put in arr
//         arr[index] = val;
//     }
//     //dequeue
//     int dequeue(int qn){
//         //check if queue is empty
//         if (front[qn-1] == -1)
//         {
//             cout << "Queue UnderFlow " << endl;
//             return -1;
//         }

//         //find which index we have to pop
//         int index = front[qn-1];    

//         //front ko age badhao
//         front[qn-1] = next[index];      //line 56-78 reverse of each other

//         //manage free space
//         next[index] = freespot; // jo freespot me value hai usse next[index] me do
//         freespot = index;   //freespot = 0
//         return arr[index]; 
//     }
// };

// int main() {

//     kqueue q(10, 3);
//     q.enqueue(10, 1);
//     q.enqueue(15,1);
//     q.enqueue(20, 2);
//     q.enqueue(25,1);

//     cout << q.dequeue(1) << endl;
//     cout << q.dequeue(2) << endl;
//     cout << q.dequeue(1) << endl;
//     cout << q.dequeue(1) << endl;

//     cout << q.dequeue(1) << endl;

//     return 0;
// }