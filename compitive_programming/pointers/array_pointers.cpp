#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10];
    cout<<a<<endl;
    cout<<&a[0]<<endl;
    a[0] = 5;
    a[2] = 15;
    cout<<*a<<endl;
    cout<<*(a+2)<<endl;
    //diff between array and pointer as pointer gets a newly allocated space of 8 bytes

    //1.& operator
    int *p = &a[0];
    cout<<"Here story begins\n"<<a<<endl;
    cout<<&a<<endl;
    cout<<p<<endl;
    cout<<&p<<endl; //defines a new address of p(8 byte memory)
    //2.sizeof
    cout<<sizeof(a)<<endl;
    cout<<sizeof(p)<<endl;
    //3.a can't be reassigned
    p = a+3;
    cout<<p<<endl;
    //a = a+3; //error shown

}