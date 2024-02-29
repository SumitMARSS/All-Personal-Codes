#include <bits/stdc++.h>
using namespace std;

int main()
{
    //basics play with pointers
    // int i = 10;
    // int *p = &i;
    // int *q = p;
    // cout<<i<<endl;
    // cout<<p<<endl;
    // cout<<*p<<endl;
    // i++;
    // cout<<i<<endl;
    // cout<<*p<<endl;
    // (*p)++;
    // cout<<i<<endl;
    // cout<<*p<<endl;
    // *p = 23;
    // cout<<i<<endl;
    // cout<<*p<<endl;
    // cout<<*q<<endl;

    /*
    int i;
    cout<<i<<endl;
    i++;
    cout<<++i<<endl;
    //int *p;
    //to overcome the dangerous update from any given garbage value just assign some value to pointer 
    //or if no value is there then assign 0 to the pointer
    int *p = 0// or NULL; //null pointer hence we now get error in our code better then getting some garbage update
    cout<<p<<endl;
    cout<<sizeof(p)<<endl;
    cout<<*p<<endl;
    (*p)++;//update any random location value which is stored as garbage value in p
    cout<<*p<<endl;
    return 0;
    */

   // Pointer's Arthimatic 
    // int i = 10;
    // int *p = &i;
    // cout<<p<<endl;
    // p = p+2;
    // cout<<p<<endl;
    // // 0xbfa25ff714
    // // 0xbfa25ff71c (c -> 12) move 8 bytes forward for int i
    // p = p-2;
    // cout<<p<<endl;
    double d;
    double *dp = &d;
    cout<<dp<<endl;
    dp++;
    cout<<dp<<endl;
}