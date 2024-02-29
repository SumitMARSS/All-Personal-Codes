#include <bits/stdc++.h>
using namespace std;

//approch 1 -> using xor
// int findUnique(int *arr, int size)
// {
//     //Write your code here
//     int ans = 0;
//     for(int i=0;i<size;i++){
//         ans = ans^arr[i];
//     }
//     return ans;
// }

//approch 2 -> if we get two equal number then set 0 at that place
// int findUnique(int *arr, int size)
// {
//     //Write your code here
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i+1; j < size; j++)
//         {
//             if (arr[i] == arr[j])
//             {
//                 arr[i] = 0;
//                 arr[j] = 0;
//                 break;
//             }
//         }
//     }
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i]!= 0)
//         {
//             return arr[i];
//         }
//     }
//     return 0;
// }


int twofindUnique(int *arr, int size)
{
    //Write your code here
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans^arr[i];
    }
    //now we have 2 unique element in xor
    
    
}

int main(){
    int arr[] = {2,4,6,8,45,3,2,3,4,6,8};
    //cout<<findUnique(arr,11)<<endl;
    cout<<twofindUnique(arr,11)<<endl;
}