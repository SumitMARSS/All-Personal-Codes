#include <iostream>
#include <math.h>
#include <climits>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number n for an array's element\n";
    cin>>n;
    int arr[n],key,t;
    for (int i = 0; i< n; i++)
    {
        cin>>arr[i];
    }
    cout<<"The elements in array are:\n";
    for (int i = 0; i< n; i++)
    {
        cout<<arr[i]<<" ";
    }
    key=n;
    while (key>0)
    {
        for (int i = 0; i < key; i++)
        {
            if (arr[i]>arr[i+1])
            {
                t=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=t;
            }
        }
        key--;
    }
    cout<<"\nThe final elements in array are:\n";
    for (int i = 0; i< n; i++)
    {
        cout<<arr[i]<<" ";
    }
}