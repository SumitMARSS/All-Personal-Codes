#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> s; //creation
    s.push(3);  //push
    s.push(5);
    s.push(10);
    s.pop();    //pop
    //top element
    cout<<"Stack peek/top element ->> "<<s.top()<<endl;
    //checking for empty
    if (s.empty())
    {
        cout<<"Stack is empty "<<endl;
    }else
    {
        cout<<"Stack is not empty "<<endl;
    }
    //size
    cout<<"Size of stack is: -> "<<s.size()<<endl;
}