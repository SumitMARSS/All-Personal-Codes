#include <iostream>
#include <math.h>
using namespace std;
int fiboo(int x,int y)
{
    int sum;
    sum=x+y;
    cout<<sum<<endl;
    return sum;
}
int main()
{
    int n,k,t1=0,t2=1;
    cout<<"Enter the terms of fibo series\n";
    cin>>n;
    cout<<"Fiboo series is:..\n";
    cout<<t1<<"\n"<<t2<<endl;
    for (int i = 1; i < n; i++)
    {
        k=fiboo(t1,t2);
        t1=t2;
        t2=k;
    }
}