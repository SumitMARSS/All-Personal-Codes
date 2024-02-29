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
    int n,k;
    cout<<"Enter the number for fact\n";
    cin>>n;
    k=fact(n);
    cout<<"Fact is:..\n"<<k;
}