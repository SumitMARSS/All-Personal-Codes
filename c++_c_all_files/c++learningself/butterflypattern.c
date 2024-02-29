#include <iostream>
using namespace std;
int main()
{
    int n,row,i,j;
    cout<<("Enter the number of rows:\n");
    cin>>row;
    cout<<("\n");
    n= 2*row;
    for ( i =1 ; i <=row ; i++)
    {
        for ( j =1; j <= n ; j++)
        {
            if (j<=i || j> n-i)
            {
                cout<<("* ");
            }
            else
            {
                cout<<("  ");
            }
        }
        cout<<("\n");
    }
    for ( i =row ; i >=1 ; i--)
    {
        for ( j =1; j <= n ; j++)
        {
            if (j<=i || j> n-i)
            {
                cout<<("* ");
            }
            else
            {
                cout<<("  ");
            }
        }
        cout<<("\n");
    }
    return 0;
}