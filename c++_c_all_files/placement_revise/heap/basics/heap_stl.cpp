#include <bits/stdc++.h>
using namespace std;

int main(){

    //max heap

    // priority_queue<int>max_heap;
    // max_heap.push(35);
    // max_heap.push(5);
    // max_heap.push(3);
    // max_heap.push(15);
    // cout<<" Max heap top element -> "<<endl;
    // cout<<max_heap.top()<<endl;
    // max_heap.pop();
    // cout<<" Max heap top element -> "<<endl;
    // cout<<max_heap.top()<<endl;
    // max_heap.pop();
    // cout<<" Max heap top element -> "<<endl;
    // cout<<max_heap.top()<<endl;
    // cout<<" Max heap size  -> "<<endl;
    // cout<<max_heap.size()<<endl;
    // if(max_heap.empty()){
    //     cout<<" Your max_heap is empty "<<endl;
    // }
    // else
    // {
    //     cout<<" Your max_heap is not empty "<<endl;
    // }
    
    //min heap
    priority_queue<int, vector<int>, greater<int> >min_heap;
    min_heap.push(35);
    min_heap.push(5);
    min_heap.push(3);
    min_heap.push(15);
    cout<<" min_heap top element -> "<<endl;
    cout<<min_heap.top()<<endl;
    min_heap.pop();
    cout<<" min_heap top element -> "<<endl;
    cout<<min_heap.top()<<endl;
    min_heap.pop();
    cout<<" min_heap top element -> "<<endl;
    cout<<min_heap.top()<<endl;
    cout<<" min_heap size  -> "<<endl;
    cout<<min_heap.size()<<endl;
    if(min_heap.empty()){
        cout<<" Your min_heap is empty "<<endl;
    }
    else
    {
        cout<<" Your min_heap is not empty "<<endl;
    }
    
}