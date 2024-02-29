#include <iostream>
#include <math.h>
#include <climits>
using namespace std;
/*
int main()
{
    int n;
    cout<<"Enter the number n for an array's element\n";
    cin>>n;
    int arr[n],max,min;
    max=INT_MAX;
    min=INT_MIN;
    for (int i = 0; i< n; i++)
    {
        cin>>arr[i];
    }
    cout<<"The elements in array are:\n";
    for (int i = 0; i< n; i++)
    {
        cout<<arr[i]<<" ";
    }
    max=arr[0];
    for (int i = 0; i< n; i++)
    {
        cout<<arr[i]<<" ";
        if (max<=arr[i])
        {
            max=arr[i];
        }
        else
        {
            continue;
        }
    }
    min=arr[0];
    for (int i = 0; i< n; i++)
    {
        if (min>=arr[i])
        {
            min=arr[i];
        }
        else
        {
            continue;
        }
    }
    cout<<"\nMax and Min array are:\n"<<max<<"\t"<<min<<endl;
}*/

int main()
{
    int n;
    cout<<"Enter the number n for an array's element\n";
    cin>>n;
    int arr[n],max1,min1;
    max1=INT_MIN;
    min1=INT_MAX;
    for (int i = 0; i< n; i++)
    {
        cin>>arr[i];
    }
    cout<<"The elements in array are:\n";
    for (int i = 0; i< n; i++)
    {
        cout<<arr[i]<<" ";
    }
    for (int i = 0; i< n; i++)
    {
        max1=max(max1,arr[i]);
        min1=min(min1,arr[i]);
    }
    cout<<"\nMax and Min array are:\n"<<max1<<"\t"<<min1<<endl;
}