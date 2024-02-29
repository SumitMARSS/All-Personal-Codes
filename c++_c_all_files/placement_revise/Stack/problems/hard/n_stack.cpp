#include <bits/stdc++.h> 

//approch - 2 //optimisd way  space complexity -  O(s+n)   &&   time complex = push/pop = O(1)

class NStack
{
    int *arr;
    int *top;
    int *next;
    int freespace;
    int no_of_stack;
    int size_of_arr;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
            no_of_stack = N;
            size_of_arr = S;
            //initialising all stack value -1
            top = new int[no_of_stack];
            for(int i=0; i<no_of_stack; i++){
                top[i] = -1;
            }
            arr = new int[size_of_arr];
            //saving the next location of freespace
            next = new int[size_of_arr];
            for(int i=0; i<size_of_arr; i++){
                next[i] = i+1;
            }
            next[size_of_arr - 1] = -1; //when stack space end
            freespace = 0;  //start space of array

    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check if stack is full or overflow
        if(freespace == -1){
            return false;
        }

        //step - 1 //find index
        int index = freespace;
        //step - 2 //update freespace
        freespace = next[index];
        //step - 3 //put data in stack
        arr[index] = x;
        //step - 4 
        //update next as data is inserted in arr -> defination of next changed
        next[index] = top[m-1]; //points next element after stack top
        //step - 5 //update top value
        top[m-1] = index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //stack is empty
        if(top[m-1] == -1){
            return -1;
        }
        // just a reverse order of push
        int index = top[m-1];   //getting the top eleement index
        top[m-1] = next[index]; //updating the top value with next of top index 
        // again storing next arr for the next freespace like at 2nd index store 3(next free address location)
        next[index] = freespace;   
        //again storing location for the free location
        freespace = index;
        return arr[index];
    }
};