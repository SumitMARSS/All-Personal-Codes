#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main(){
    deque<int>d;

    d.push_back(12);
    d.push_back(18);
    d.push_back(20);
    cout<<"front element -> "<<d.front()<<endl;
    cout<<"Back element -> "<<d.back()<<endl;  
    d.push_front(22);
    cout<<"front element -> "<<d.front()<<endl;
    cout<<"Back element -> "<<d.back()<<endl;  
    d.pop_front();
    cout<<"front element -> "<<d.front()<<endl;
    cout<<"Back element -> "<<d.back()<<endl;  
    d.pop_back(); 
    cout<<"front element -> "<<d.front()<<endl;
    cout<<"Back element -> "<<d.back()<<endl;  
}