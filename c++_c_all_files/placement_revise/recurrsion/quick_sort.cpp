#include <bits/stdc++.h>
using namespace std;

// int partition(int *arr,int start,int end){
//     int pivot = arr[start];
//     int count = 0;
//     for (int i = start+1 ; i <= end; i++)
//     {
//         if (arr[i] <= pivot)
//         {
//             count++;
//         }
//     }
//     int pivotIndex = start + count;
//     swap(arr[pivotIndex],arr[start]);

//     int j = start, k = end;
//     while ( j < pivotIndex && k>pivotIndex) // we can also write  (j <= k) as condition
//     {
//         while (arr[j] <= pivot)
//         {
//             j++;
//         }
//         while (arr[k] > pivot)
//         {
//             k--;
//         }
//         if ( j < pivotIndex && k>pivotIndex )   // we can also write  j <= k as condition
//         {
//             swap(arr[j++],arr[k--]);
//         }
//     }
//     return pivotIndex;
// }


// void quick_sort(int *arr,int start,int end){
//     if (start >= end)
//     {
//         return;
//     }
//     int p = partition(arr,start,end);
//     quick_sort(arr,start,p-1);
//     quick_sort(arr,p+1,end);
// }

// int main(){
//     int arr[] = { 2,23,4,77,34,51,9,34};
//     quick_sort(arr,0,7);
//     for (int i = 0; i < 8; i++)
//     {
//         cout<<*(arr+i)<<" ";
//     }cout<<endl;
    
// }

//complete understood

int partition(int *arr,int start,int end){
    int pivot = arr[start];
    int count=0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] < pivot)
        {
            count++;
        }
    }
    int pivotIndex = start+count;
    swap( arr[pivotIndex], arr[start]); // we made the element in right place

    // all element less then pivotIndex will be in left and vice-versa

    int a = start, b=end;
    while (a < pivotIndex && b > pivotIndex)
    {
        while (arr[a] < pivot)
        {
            a++;
        }
        while (arr[b] > pivot)
        {
            b--;
        }
        // if (a < pivotIndex && b > pivotIndex)
        // {
        //     swap(arr[a++],arr[b--]);
        // }
        swap(arr[a++],arr[b--]);
    }
    return pivotIndex;
}

void quick_sort(int *arr,int start, int end){
    if (start >= end)
    {
        return;
    }
    int p = partition(arr,start,end);
    quick_sort(arr,start,p-1);
    quick_sort(arr,p+1,end);
}

int main(){
    int arr[] = {12,2,78,43,2,34,5,25,1,6,9};
    int n = 11;
    cout<<"Initial arrray: -> "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<< *(arr+i)<<" ";
    }cout<<endl;

    quick_sort(arr,0,n-1);

    cout<<"Sorted arrray: -> "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<< *(arr+i)<<" ";
    }cout<<endl;
}