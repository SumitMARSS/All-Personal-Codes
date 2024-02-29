#include <bits/stdc++.h>
using namespace std;
//similar to double link list that's why for erasing purpose use O(n)
int main(){

    list <int> l;
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_front(5);
    cout<<"Element in list"<<endl;
    for (auto &i : l)
    {
        cout<<i<<endl;
    }
//pop operation

    // l.pop_back();
    // cout<<"After pop from back"<<enll;
    // for (auto &i : l)
    // {
    //     cout<<i<<endl;
    // }
    // l.pop_front();
    // cout<<"After pop from front"<<enll;
    // for (auto &i : l)
    // {
    //     cout<<i<<endl;
    // }


    //accress front and last element
    cout<<"Front: "<<l.front()<<"  Back: "<<l.back()<<endl;
    list <int> l1;
//checking list is empty or not
    cout<<"list is empty or not -> "<<l.empty()<<endl;
    cout<<"list is empty or not -> "<<l1.empty()<<endl;
    
    cout<<"Element before erasing"<<endl;
    for (auto &i : l)
    {
        cout<<i<<endl;
    }
//erasing the list elements
    l.erase(l.begin());
    cout<<"Element after erasing"<<endl;
    for (auto &i : l)
    {
        cout<<i<<endl;
    }
}