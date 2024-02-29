#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int>q;
    q.push(3);
    q.push(4);
    q.push(9);
    cout<<" Size of queue ->  "<<q.size()<<endl;
    q.pop();
    cout<<" Size of queue ->  "<<q.size()<<endl;
    cout<<" Front element in queue -> "<<q.front()<<endl;
    //no rear element in queue
    //cout<<" Rear elemet in queue -> "<<q.rear()<<endl;
    q.pop();
    cout<<" Front element in queue -> "<<q.front()<<endl;
    if (q.empty())
    {
        cout<<" Queue is empty "<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }
    q.pop();
    
    if (q.empty())
    {
        cout<<" Queue is empty "<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }
    cout<<" Front element in queue -> "<<q.front()<<endl;//garbage value




}