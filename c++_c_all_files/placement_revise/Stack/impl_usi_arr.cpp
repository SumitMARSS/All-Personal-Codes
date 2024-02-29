#include <iostream>
using namespace std;

//implementation of stack using array

class stack{
    //properties
    public:
    int top;
    int *arr;
    int size;
    //behaviour
    stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int val){
        if ( (size - top) >= 1)
        {
            top++;
            arr[top] = val;
        }else
        {
            cout<<" Stack gets overflow "<<endl;
        }
    }

    void pop(){
        if (top >=0)
        {
            top--;
        }else
        {
            cout<<"Stack gets underflow "<<endl;
        }
    }

    int peek(){
        if (top >=0)
        {
            return arr[top];
        }else
        {
            cout<<" STACK IS empoty"<<endl;
            return -1;
        }
    }

    bool isempty(){
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

int main(){
    stack st(5);
    st.push(13);
    st.push(14);
    st.push(15);
    st.push(13);
    st.pop();
    cout<<" stack top element is -> "<<st.peek()<<endl;
    st.pop();
    cout<<" stack top element is -> "<<st.peek()<<endl;
    st.pop();
    cout<<" stack top element is -> "<<st.peek()<<endl;
    st.pop();
    cout<<" stack top element is -> "<<st.peek()<<endl;
    st.pop();
    cout<<" stack top element is -> "<<st.peek()<<endl;
    if (st.isempty())
    {
        cout<<"Stack is empty"<<endl;
    }else
    {
        cout<<"Stack is not empty"<<endl;
    }
    
    
}


//implementation of 2 stack in a array
//  fill array from opposite sides until (top2 - top1) > 1 for max utilization of space

// #include <bits/stdc++.h> 
// class TwoStack {
//     int size;
//     int *arr;
//     int top1;
//     int top2;
// public:

//     // Initialize TwoStack.
//     TwoStack(int s) {
//         // Write your code here.
//         this->size = s;
//         arr = new int[s];
//         top1 = -1;
//         top2 = s;
//     }
    
//     // Push in stack 1.
//     void push1(int num) {
//         // Write your code here.
//         if(top2 - top1 >1){
//             top1++;
//             arr[top1] = num;
//         }
//         return;
//     }

//     // Push in stack 2.
//     void push2(int num) {
//         // Write your code here.
//         if(top2 - top1 >1){
//             top2--;
//             arr[top2] = num;
//         }
//         return;
//     }

//     // Pop from stack 1 and return popped element.
//     int pop1() {
//         // Write your code here.
//         if(top1 >=0){
//             int ans = arr[top1];
//             top1--;
//             return ans;
//         }else{
//             return -1;
//         }
//     }

//     // Pop from stack 2 and return popped element.
//     int pop2() {
//         // Write your code here.
//         if(top2 < size){
//             int ans = arr[top2];
//             top2++;
//             return ans;
//         }else{
//             return -1;
//         }
//     }
// };
