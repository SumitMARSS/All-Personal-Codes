#include <bits/stdc++.h>
using namespace std;

void print(int *p){
    cout<<*p<<endl;
}
void incrementPointer(int *p){
    p = p+1;
}
void increment(int *p){
    (*p)++; //here we are going to same address and then made changes on that address
}
//a[] never passes, it always pass as a pointer
int sum(int *a,int size){
    int sum=0;
    cout<<sizeof(a)<<endl; //8 size of pointer
    for (int i = 0; i < size; i++)
    {
        sum += *(a+i);
    }
    return sum;
}
int main()
{
    // int i = 10;
    // int *p = &i;
    // print(p);
    // cout<<p<<endl;
    // incrementPointer(p);//not reflect the changes assume both are in 2 cheet and we are changing 1 of them 
    // cout<<p<<endl;
    // cout<<*p<<endl;
    // increment(p);
    // cout<<*p<<endl;

    //array and pointer
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    cout<<sizeof(arr)<<endl; //40 size 
    cout<<sum(arr,10)<<endl;

}