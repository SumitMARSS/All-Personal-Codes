#include <iostream>
#include <math.h>
#include <climits>
#include <string>
using namespace std;

void swapp(int *a, int *b)
{
    int temp;
    temp= *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int l,int r)
{
    int pivot = a[r];
    int i=l-1;
    for (int j = l; j <= r-1; j++)
    {
        if (a[j]<pivot)
        {
            i++;
            //mam method
            //swapp(a,i,j);
            swapp(&(a[i]),&(a[j]));
        }
    }
    swapp(&(a[i+1]) ,&(a[r]));
    //mam method
    //swapp(a,i+1,r);
    return i+1;
    
}

void quick_sort(int a[], int l, int r)
{
    if (l<r)
    {
        int p= partition(a, l,r);
        quick_sort(a,l,p-1);
        quick_sort(a,p+1,r);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements:\n";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"Your elements are:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
    quick_sort(a,0,n);
    cout<<"\nYour sorted elements are\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
}