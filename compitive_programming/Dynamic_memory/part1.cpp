#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i=10; //memory allocated in stack
    //using [new int] we can allocate memory in heap but it only give us address, we have to store somewhere
    int *p = new int;
    *p = 11;
    cout<<*p<<endl;
    delete p;
    //similarly
    // char *c = new char;
    // delete c;//for deallocation otherwise memory gets leaked or wasted
    // double *pd = new double;
    // delete pd;

    //dynamic array
    //int *a = new int[50]; //50*4 =200byte in heap and 8 byte in stack
    int n,max=-1;
    cout<<"Enter no of array you wish\n";
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"a["<<i<<"] ->";
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (max<arr[i])
        {
            max = arr[i];
        }
    }
    cout<<"Max no.. is "<<max<<endl;
    delete [] arr;
}