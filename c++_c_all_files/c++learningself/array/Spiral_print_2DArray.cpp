#include <iostream>
#include <math.h>
#include <climits>
using namespace std;

//*
int main()
{
    int n,m;
    cout<<"Enter the number n for an array's rows and m for column array\n";
    cin>>n;
    cin>>m;
    int arr[n][m];
    cout<<"Enter the matrix\n";
    for (int i = 0; i< n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"The elements in array matrix are:\n";
    for (int i = 0; i< n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    //spiral print logic
    int row_start=0, row_end=n-1, column_start=0, column_end=m-1;
    while (row_start<=row_end && column_start<=column_end)
    {
        //first row print
        for (int col = column_start; col <= column_end; col++)
        {
            cout<<arr[row_start][col]<<"  ";
        }
        row_start++;
        //last column print
        for (int row = row_start; row <= row_end; row++)
        {
            cout<<arr[row][column_end]<<"  ";
        }
        column_end--;
        //last row print
        for (int lcol = column_end; lcol >=column_start; lcol--)
        {
            cout<<arr[row_end][lcol]<<"  "; 
        }
        row_end--;
        //first column print
        for (int frow = row_end; frow >= row_start; frow--)
        {
            cout<<arr[frow][column_start]<<"  ";
        }
        column_start++;
    }
}
//*