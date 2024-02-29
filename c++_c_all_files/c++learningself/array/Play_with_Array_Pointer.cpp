#include <iostream>
#include <math.h>
#include <climits>
using namespace std;

//*
int main()
{
    int n;
    cin>>n;
    //int arr[4]={20,30,40,50};
    int arr[n];
    int *ptr=arr;
    for (int i = 0; i < n; i++)
    {
        cin>>*ptr;
        ptr++;
    }
    ptr=arr;
    for (int i = 0; i < n; i++)
    {
        cout<<*ptr<<endl;
        ptr++;
    }
    /*for (int i = 0; i < n; i++)
    {
        cout<<*(arr+i)<<endl;
    }*/
}
//*