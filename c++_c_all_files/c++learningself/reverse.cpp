#include <iostream>
#include <cmath>
using namespace std;
main()
{
    int a,r,reverse=0;
    cout<<"Enter the number\n";
    cin>>a;
    while (a!=0)
    {
        r=a%10;
        reverse=reverse*10+r;
        a=a/10;
    }
    cout<<reverse<<" is the given number";
    return 0;
    
}