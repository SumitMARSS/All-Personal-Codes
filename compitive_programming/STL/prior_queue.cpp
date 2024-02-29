#include <iostream>
#include <queue>
using namespace std;

int main(){
    //defining max-heap
    priority_queue <int> maxi; //defining max priority queue
    maxi.push(2);
    maxi.push(8);
    maxi.push(5);
    maxi.push(12);
    int n = maxi.size();
    cout<<"Size of min-heap: "<<n<<endl;
    cout<<"Minimum heap poping: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<maxi.top()<<endl;
        maxi.pop();
    }
    //defining mini-heap
    priority_queue <int, vector<int>, greater<int> > mini;
    mini.push(4);
    mini.push(8);
    mini.push(2);
    mini.push(1);
    mini.push(3);
    int m = mini.size();
    cout<<"Size of min-heap "<<m<<endl;
    cout<<"Minimum heap poping: "<<endl;
    for (int i = 0; i < m; i++)
    {
        cout<<mini.top()<<endl;
        mini.pop();
    }
    cout<<"Khali hai kya bhai ??? "<<mini.empty()<<endl;
    
}