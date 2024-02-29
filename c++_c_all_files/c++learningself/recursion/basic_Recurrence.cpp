#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
//sum of n numbers
int sum(int n)
{
    if (n==0)
    {
        return 0;
    }
    else
    {
        int pre_sum=sum(n-1);
        return n+ pre_sum;
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<sum(n);;
    return 0;
}*/


/*
//power of n^p
int power(int n,int p)
{
    if (p==0)
    {
        return 1;
    }
    else
    {
        int pre_value=power(n,p-1);
        return n* pre_value;
    }
}
int main()
{
    int n,p;
    cin>>n>>p;
    cout<<power(n,p);
    return 0;
}
*/
/*
//factorial
int fact(int n)
{
    if (n==0 || n==1)
    {
        return 1;
    }
    else
    {
        int f=fact(n-1);
        return n*f;
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}*/
//fibonacii series
int fiboo(int n)
{
    /*if (n==0)
    {
        return 0;
    }
    else if (n==1)
    {
        return 1; 
    }*/
    if (n==0 || n==1)  //base conditions
    {
        return n;
    } 
    else
    {
        return fiboo(n-1)+fiboo(n-2);
    } 
}
int main()
{
    int n;
    cin>>n;
    for ( int i = 0; i < n; i++)
    {
        cout<<fiboo(i)<<endl;
    }
    return 0;
}