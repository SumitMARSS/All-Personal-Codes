#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int end)
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
    //method 1 apna college method
    int p=0,s=0,k=l;
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
    /*
    //method 2
    int p=0,s=0;
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
            s++;
        }
    }*/
}

void merge_sort(int arr[], int l, int end)
{
    int mid;
    if (l<end)
    {
        mid = (l+end)/2;
        merge_sort(arr,l, mid);
        merge_sort(arr,mid+1, end);
        merge(arr,l,mid,end);//merging the last 2 small subarray with sorting
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
    merge_sort(arr,start, n);
    cout<<"Sorted array\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
