#include <iostream>
#include <math.h>
#include <climits>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number n for an array's element\n";
    cin>>n;
    int arr[n],key,t,s=0;
    for (int i = 0; i< n; i++)
    {
        cin>>arr[i];
    }
    cout<<"The elements in array are:\n";
    for (int i = 0; i< n; i++)
    {
        cout<<arr[i]<<" ";
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[i])
            {
                t=arr[j];
                arr[j]=arr[i];
                arr[i]=t;
            }
        }
    }
    cout<<"The final elements in array are:\n";
    for (int i = 0; i< n; i++)
    {
        cout<<arr[i]<<" ";
    }
}