#include <bits/stdc++.h>
using namespace std;

int main(){

    deque <int> d;
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_front(5);
    cout<<"Element in deque"<<endl;
    for (auto &i : d)
    {
        cout<<i<<endl;
    }
//pop operation

    // d.pop_back();
    // cout<<"After pop from back"<<endl;
    // for (auto &i : d)
    // {
    //     cout<<i<<endl;
    // }
    // d.pop_front();
    // cout<<"After pop from front"<<endl;
    // for (auto &i : d)
    // {
    //     cout<<i<<endl;
    // }

// element at an index
    cout<<"Element at 2 index: "<<d.at(2)<<endl;
    //accress front and last element
    cout<<"Front: "<<d.front()<<"  Back: "<<d.back()<<endl;
    deque <int> d1;
//checking deque is empty or not
    cout<<"Deque is empty or not -> "<<d.empty()<<endl;
    cout<<"Deque is empty or not -> "<<d1.empty()<<endl;
    
    cout<<"Element before erasing"<<endl;
    for (auto &i : d)
    {
        cout<<i<<endl;
    }
//erasing the deque elements
    d.erase(d.begin(), d.begin()+2);
    cout<<"Element after erasing"<<endl;
    for (auto &i : d)
    {
        cout<<i<<endl;
    }
}