#include <iostream>
#include <math.h>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*
void wave_sort(int a[],int n)
{
    for (int i = 1; i < n; i=i+2)
    {
        if (a[i]<a[i-1])
        {
            swap((a+i),(a+(i-1)));
        }
        else if (a[i+1]>a[i] && i<= n-2)
        {
            swap((a+i),(a+(i+1)));
        }
        else
        {
            continue;
        } 
    }
}*/
//mam algo
void wave_sort(int a[],int n)
{
    for (int i = 1; i < n; i=i+2)
    {
        if (a[i]>a[i-1])
        {
            swap((a+i),(a+(i-1)));
        }
        else if (a[i+1]<a[i] && i<= n-2)
        {
            swap((a+i),(a+(i+1)));
        }
        else
        {
            continue;
        } 
    }
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
    wave_sort(a,n);
    
    cout<<"\nYour wave arrays are:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
    return 0;
}