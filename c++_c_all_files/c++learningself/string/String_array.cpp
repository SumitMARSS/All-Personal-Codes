#include <iostream>
#include <math.h>
#include <climits>
using namespace std;

//*
int main()
{
    bool check=1;
    int n;
    cout<<"Enter the number n char array\n";
    cin>>n;
    char arr[n+1];
    cin>>arr;
    cout<<"Strings in array are:\n";
    for (int i = 0; i < n; i++)
    {
        if (arr[i]!=arr[n-1-i])
        {
            check=0;
            break;
        }
    }
    if (check==1)
    {
        cout<<"Given string "<<arr<<" is pelindrome.\n";
    }
    else
    {
        cout<<"Not a pelidrome word "<<arr;
    }
}
//*