#include <bits/stdc++.h>
using namespace std;

// //inversion count

// int count(int *arr,int start, int end){
//     int mid = start + (end-start)/2;
//     int l1 = mid - start +1;
//     int l2 = end - mid;
//     int *first = new int [l1];
//     int *second = new int [l2];
//     for (int i = 0; i < l1; i++)
//     {
//         first[i] = arr[start+i];
//     }
//     for (int i = 0; i < l2; i++)
//     {
//         second[i] = arr[mid+1+i];
//     }
//     int a=0,b=0,c=start;
//     while (a < l1 && b<l2)
//     {
//         if (first[a] < second[b])
//         {
//             count++;

//         }
        
//     }
    
    

// }

// int inversion_count(int *arr,int start,int end){
//     if (start >= end)
//     {
//         return 0;
//     }
    
//     int mid = start + (end-start)/2;
//     return inversion_count(arr,start,mid);
//     return inversion_count(arr,mid+1,end);
//     return count(arr,start,end);
// }


// int main(){
//     int arr[] = {8,4,2,1};

//     cout<<inversion_count(arr,0,3)<<endl;
    
// }

int main(){
    string str = "su     mhty i  tyhty";
    cout<<str.length()<<endl;
    int count = 0;
    for (int i = 0; i < str.length()-1; i++)
    {
        if (str[i] == ' ')
        {
            for (int j = count; j < str.length(); j++)
            {
                str[j] = str[j+1];
            }
            count--;
            i=count;
        }
        count++;
    }
    //cout<<count<<endl;
    cout<<str<<endl;
}