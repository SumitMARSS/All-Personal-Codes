#include <iostream>
#include <math.h>
using namespace std;
int fact(int x)
{
    int k=1;
    for (int i = 1; i <= x; i++)
    {
        k=k*i;
    }
    return k;   
}
int main()
{
    int n,r,result;
    cout<<"Enter the number n\n";
    cin>>n;
    cout<<"Enter the number r\n";
    cin>>r;
    //no need of assigning new variables like k=fact(n)  ....etc
    result=fact(n)/(fact(r)*fact(n-r));
    cout<<"nCr value is:..\n"<<result;
}