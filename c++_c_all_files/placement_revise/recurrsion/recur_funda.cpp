//say digits

#include <bits/stdc++.h>
using namespace std;
// void say_digits(int  n){
//     int digit;
//     if (n == 0)
//     {
//         return ;
//     }
//     //write here for head recursion the processing part
    
//     say_digits(n/10); 
//     //tail recursion
//     digit = n % 10;
//     unordered_map<int,string> m = {
//         {0,"zer0"},
//         {1,"one"},
//         {2,"two"},
//         {3,"three"},
//         {4,"four"},
//         {5,"five"},
//         {6,"six"},
//         {7,"seven"},
//         {8,"eight"},
//         {9,"nine"}
//     };
//     cout<<m[digit]<<endl;
    
// }

// int main() {
//     // Write C++ code here
//     std::cout << "Hello world!"<<endl;
//     int digit;
//     cin>>digit;
//     say_digits(digit);
//     return 0;
// }

//n- strair prob - no of ways you can climb n stairs you have options to climb 0 or 1 stairs

// #include <iostream>
// using namespace std;
// int count_no_stairs(int  n){
//     // no of ways to reach 0 stairs if you are underground
//     if( n <0){
//         return 0;
//     }
//     // no of ways to reach 0 stairs 
//     else if (n == 0)
//     {
//         return 1;
//     }
//     return count_no_stairs(n-1) + count_no_stairs(n-2); 
    
// }

// int main() {
//     // Write C++ code here
//     std::cout << "Hello world!"<<endl;
//     int n_stair;
//     cin>>n_stair;
//     cout<<count_no_stairs(n_stair)<<endl;
//     return 0;
// }



// fiboo series

// #include <iostream>
// using namespace std;
// int fiboo(int  x){
//     if( x==0){
//         return 0;
//     }
//     else if (x == 1)
//     {
//         return 1;
//     }
//     return fiboo(x-1) + fiboo(x-2); 
    
// }

// int main() {
//     // Write C++ code here
//     std::cout << "Hello world!"<<endl;
//     int n;
//     cin>>n;
//     for (int i = 0; i < n; i++)
//     {
//         cout<<fiboo(i)<<" ";
//     }
//     //cout<<fiboo(n)<<" "; //fiboo of nth place as indexing start from 0
//     return 0;
// }



// counting

// #include <iostream>
// using namespace std;
// void counting(int  x){
//     if( x==0){
//         return ;
//     }
//     cout<<x<<endl; //tail recursion
//     counting(x-1); 
//     //cout<<x<<endl; //head recursion if we use this
// }

// int main() {
//     // Write C++ code here
//     std::cout << "Hello world!"<<endl;
//     int n;
//     cin>>n;
//     counting(n);
//     return 0;
// }

// 2^n

// #include <iostream>
// using namespace std;
// int power(int  x){
//     if( x==0){
//         return 1;
//     }
//     return power(x-1) * 2; 
// }

// int main() {
//     // Write C++ code here
//     std::cout << "Hello world!"<<endl;
//     int n;
//     cin>>n;
//     cout<<power(n)<<endl;
//     return 0;
// }


//n! recursion

// #include <iostream>
// using namespace std;
// int fact(int  x){
//     if(x == 1 || x==0){
//         return 1;
//     }
//     return fact(x-1) * x; 
// }

// int main() {
//     // Write C++ code here
//     std::cout << "Hello world!"<<endl;
//     int n;
//     cin>>n;
//     cout<<fact(n)<<endl;

//     return 0;
// }


// is sorted 

// bool is_sorted(vector<int> &v, int index = 0) {
//     if (index >= v.size() - 1) {
//         return true;
//     }
//     if (v[index] > v[index + 1]) {
//         return false;
//     }
//     return is_sorted(v, index + 1);
// }

// // bool is_sorted(int arr[], int size){
// //     if (size == 0 || size == 1)
// //     {
// //         return true;
// //     }
// //     if (arr[0] > arr[1])
// //     {
// //         return false;
// //     }
// //     return is_sorted(arr+1,size-1);
// // }

// int main(){
//     //int arr[5] = {2,4,60,8,12};
//     //cout<<is_sorted(arr,5)<<endl;
//     vector<int> v = {2, 14, 6, 8, 12};
//     cout << is_sorted(v) << endl;
    
// }

// sum of arr elements

//approch1
// int sum_recuur(int arr[], int size){
//     if (size == 0)
//     {
//         return 0;
//     }
//     return arr[size-1]+sum_recuur(arr,size-1);
// }

//approch2
// int sum_recuur(int arr[], int size){
//     if (size == 0)
//     {
//         return 0;
//     }
//     return arr[0]+sum_recuur(arr+1,size-1);
// }

// int main(){
//     int arr[] = {2,5,10,3,8,7};
//     int size = 6;
//     cout<<sum_recuur(arr,size)<<endl;
// }

// is key present or not

void print(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}

//approch1 
// bool linear_is_key_present(int *arr,int size,int key){
//     //let's check recurrsion tree
//     print(arr,size);

//     //base case
//     if (size == 0)
//     {
//         return false;
//     }
//     if(arr[0]==key){
//         return true;
//     }
//     return linear_is_key_present(arr+1,size-1,key);
// }

////approch 2
// bool linear_is_key_present(int *arr,int size,int key){
//     //let's check recurrsion tree
//     print(arr,size);

//     //base case
//     if (size == 0)
//     {
//         return false;
//     }
//     if(arr[size]==key){
//         return true;
//     }
//     return linear_is_key_present(arr,size-1,key);
// }

// int main(){
//     int arr[] = {3,2,7,5,12,54,9};
//     int key = 5;
//     int ans = linear_is_key_present(arr,7,key);
//     if (ans){
//         cout<<"Yes,present"<<endl;
//     }
//     else
//     {
//         cout<<"Not present"<<endl;
//     }
// }

//binary search using recursion

void print(int *arr,int start,int end){
    for (int i = start; i <= end; i++)
    {
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}

bool binary_search_recur(int *arr,int start,int end,int key){
    print(arr,start,end);
    if (start <= end)
    {
        int mid = start + (end - start)/2;
        cout<<"arr [mid] : -> "<<arr[mid]<<endl;
        if (key == arr[mid])
        {
            return true;
        }
        if (key > arr[mid])
        {
            return binary_search_recur(arr,mid+1,end,key);
        }
        else
        {
            return binary_search_recur(arr,start,mid-1,key);
        }
    }
    return false;
}


// bool binary_search_recur(int *arr,int start,int end,int key){
//     if (start>end)
//         return false;
//     int mid = start + (end - start)/2;
//     if (key == arr[mid])
//         return true;
//     if (key > arr[mid])
//     {
//         return binary_search_recur(arr,mid+1,end,key);
//     }
//     else
//     {
//         return binary_search_recur(arr,start,mid-1,key);
//     }
// }


int main(){
    int arr[] = { 2,4,5,8,13,15,21,41,121,212,324};
    int key = 324;
    int size = 11;
    int start = 0;
    int end = size - 1;
    cout<<binary_search_recur(arr,start,end,key)<<endl;
    return 0;
}

