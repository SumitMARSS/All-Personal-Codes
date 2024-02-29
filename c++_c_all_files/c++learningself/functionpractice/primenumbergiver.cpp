#include <iostream>
#include <math.h>
using namespace std;
void primenum(int a, int b)
{
    int i,j,s;
    cout<<"Prime numbers are:\n";
    for ( i = a+1 ; i <=b; i++)
    {
        for ( j = 2; j <= sqrt(i); j++)
        {
            if (i%j==0)
            {
                s=1;
            } 
            else
            {
                s=0;
            }  
        } 
    if (s==0)
    {
        cout<<i<<"\n";
    }
    }
}
int main()
{
    int a,b;
    cout<<("Enter 2 number b/t which you want to find prime numbers\n");
    cin>>a>>b;
    primenum(a,b);
    return 0;
}