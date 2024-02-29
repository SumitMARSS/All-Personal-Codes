#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//bit manipulation
int getbit(int n, int pos)
{
    return ((n & (1 << pos))!=0);
}
int setbit(int n, int pos){
    return (n | (1<<pos));
}
int clearbit(int n, int pos){
    int mask= (~(1<<pos));   //a simple terminology just to show we are doing some compli to get ans
    return (n & mask);
}
int updatebit(int n, int pos,int value){
    int mask= (~(1<<pos));
    n = (n & mask);
    return (n | (value<<pos));
}
int main()
{
    int n,pos,value;
    cin>>n>>pos>>value;
    //cout<<getbit(n,pos)<<endl;
    //cout<<setbit(n,pos)<<endl;
    //cout<<clearbit(n,pos)<<endl;
    cout<<updatebit(n,pos,value)<<endl;
}