/*
//problem in merge sort

//brute force code
#include <iostream>
#include <math.h>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void count_inversion(int a[],int n)
{
    int sum=0;
    cout<<"\nGiven numbers are:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i]>a[j] && i<j)
            {
                sum++;
                cout<<a[i]<<"\t"<<a[j]<<endl;
            }
        }
    }
    cout<<"The total numbers of inversion are: "<<sum<<endl;
}
int main()
{
    int n;
    cout<<"Enter the elements in array:\n";
    cin>>n;
    int a[n];
    cout<<"Enter the array 's elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"Your array are:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
    count_inversion(a,n);
    return 0;
}
*/

#include <iostream>
using namespace std;

int merge(int arr[], int l, int mid, int end)
{
    int n1=mid-l+1;
    int n2=end-mid;
    int a[n1],b[n2];
    for (int i = 0; i < n1; i++)//copying first half element for comparison
    {
        a[i]=arr[i+l];
    }
    for (int i = 0; i < n2; i++)//copying last half element for comparison
    {
        b[i]=arr[i+mid+1];
    }
    
    /*
    //method 1 apna college method
    int p=0,s=0,k=l,sum=0;
    while (p<n1 && s<n2)//if any one s or p gets equal to n1 or n2 they get out from loop
    {
        if (a[p]<b[s])
        {
            arr[k]=a[p];
            p++;
        }
        else
        {
            arr[k]=b[s];
            sum += n2-s;
            s++;
        }
        k++;
    }
    //printing all others case
    while (p<n1)
    {
        arr[k]=a[p];
        p++;
        k++;
    }
    while (s<n2)
    {
        arr[k]=b[s];
            s++;
            k++;
    }
    
    //method 2
    */
    int p=0,s=0;
    long long sum=0;
    for (int k = l; k <= end; k++)
    {
        if (a[p]<b[s])
        {
            arr[k]=a[p];//compare and copying smaller elemnt in our arr
            p++;
        }
        else
        {
            arr[k]=b[s];//compare and copying smaller elemnt in our arr
            sum+= n2-s ;
            s++;
        }
    }
    return sum;
}

long long merge_sort(int arr[], int l, int end)
{
    int mid;
    long long sum=0;
    if (l<end)
    {
        mid = (l+end)/2;
        sum +=merge_sort(arr,l, mid);
        sum +=merge_sort(arr,mid+1, end);
        sum +=merge(arr,l,mid,end);//merging the last 2 small subarray with sorting
    }
}

int main()
{
    int n,start=0;
    cout<<"Enter number of elements in array\n";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Total number of inversions are  :"<<merge_sort(arr,start, n);
    merge_sort(arr,start, n);
    cout<<"\nSorted array\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
