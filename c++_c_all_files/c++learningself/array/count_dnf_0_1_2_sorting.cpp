
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
//dnf sort by recursion
void dnf_sort(int a[], int low, int mid, int high)
{
    if (mid>high)
    {
        return;
    }
    else if (a[mid]==0)
    {
        swap((a+mid),(a+low));
        low++;
        mid++;
        dnf_sort(a,low,mid,high);
    }
    else if (a[mid]==1)
    {
        mid++;
        dnf_sort(a,low,mid,high);
    }
    else
    {
        swap((a+mid), (a+high));
        high--;
        //mid++;
        dnf_sort(a,low,mid,high);
    }

}*/
/*
//dnf sort by using loop
void dnf_sort(int a[], int n)
{
    int mid = 0, low = 0, high = n - 1;
    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap((a + low),(a + mid));
            low++;
            mid++;
            // dnf_sort(a,low,mid,high);
        }
        else if (a[mid] == 1)
        {
            mid++;
            // dnf_sort(a,low,mid,high);
        }
        else
        {
            swap((a + mid), (a + high));
            high--;
            //mid++;
            // dnf_sort(a,low,mid,high);
        }
    }
}
*/
//count sort
void count_sort(int a[], int n)
{
    int b[n];
    int k=0;
    for (int i = 0; i < n; i++)
    {
        if (k<=a[i])
        {
            k=a[i];
        }
        //k = max(k,a[i]);//max is a function in c++
    }
    int count[100]={0};
    //to give each count array size in count array
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    for (int j = 1; j <= k; j++)
    {
        count[j]+=count[j-1];
    }
    //transversing from last elemnent giving value to pre decrementer count[a[i]] in b
    for (int i = n-1; i >= 0; i--)
    {
        b[--count[a[i]]]=a[i];
    }

    for (int i = 0; i < n; i++)
    {
        a[i]=b[i];
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
        cout<<a[i]<<endl;
    }
    count_sort(a,n);
    
    cout<<"Your sorted arrays are:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}

/*
//dnf sorting or 0,1,2, sorting
int main()
{
    int n;
    cout << "Enter the elements in array:\n";
    cin >> n;
    int a[n];
    cout << "Enter the array 's elements b/t 0,1,2:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mid = 0, low = 0, high = n - 1;
    dnf_sort(a, n);
    //dnf_sort(a,low,mid,high);//use if you want to do by recurrsion
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}*/