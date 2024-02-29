//2D array Dynamically
#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cout<<"Enter m,n"<<endl;
    cin>>m>>n;
    int **p = new int*[m]; //store 10 address of pointers
    for (int  i = 0; i < m; i++)
    {
        p[i] = new int [n];
        for (int j = 0; j < n; j++)
        {
            cin>>p[i][j];
        }
    }
    for (int  i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<"p"<<i<<j<<"is ->"<<p[i][j]<<endl;
        }
    }
    //delete [][]p; we can't deallocate like this
    for (int i = 0; i < m; i++)
    {
        delete [] p[i];
    }
    delete [] p;
}