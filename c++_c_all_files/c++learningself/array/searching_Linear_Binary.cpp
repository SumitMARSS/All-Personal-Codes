#include <iostream>
#include <math.h>
#include <climits>
using namespace std;

/*mine method
int main()
{
    int n;
    cout<<"Enter the number n for an array's element\n";
    cin>>n;
    int arr[n],key,p,s;
    for (int i = 0; i< n; i++)
    {
        cin>>arr[i];
    }
    cout<<"The elements in array are:\n";
    for (int i = 0; i< n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"Enter the key term which you want to find:\n";
    cin>>key;

    for (int i = 0; i< n; i++)
    {
        if (arr[i]==key)
        {
            s=1;
            p=i;
        }
    }
    if (s==1)
    {
        cout<<"Element "<<key<<" present in "<<p<<" index\n";
    }
    else
    {
        cout<<"Element not found";
    }
}
*/

/*
best time and space complexity 
int linearsearch(int arr[],int n,int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key==arr[i])
        {
            return i;
        } 
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the number n for an array's element\n";
    cin>>n;
    int arr[n],key;
    for (int i = 0; i< n; i++)
    {
        cin>>arr[i];
    }
    cout<<"The elements in array are:\n";
    for (int i = 0; i< n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"Enter the key term which you want to find:\n";
    cin>>key;
    cout<<linearsearch(arr,n,key)<<endl;
}
*/

int binarysearch(int arr[],int n,int key)
{
    int mid,first=0,last=n;
    while (first<=last)
    {
        mid=(first+last)/2;
        if (key==arr[mid])
        {
            return mid;
        }
        else if (key>=arr[mid])
        {
            first=mid+1;
        }
        else if (key<=arr[mid])
        {
            last=mid-1;
        }
    }
    return -1; 
}

int main()
{
    int n;
    cout<<"Enter the number n for an array's element\n";
    cin>>n;
    int arr[n],key;
    for (int i = 0; i< n; i++)
    {
        cin>>arr[i];
    }
    cout<<"The elements in array are:\n";
    for (int i = 0; i< n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nEnter the key term which you want to find:\n";
    cin>>key;
    cout<<binarysearch(arr,n,key)<<endl;
}