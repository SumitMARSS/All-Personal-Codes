/*#include <iostream>
#include <math.h>
using namespace std;
void pascaltriangle(int x)
{
    int a[50][100];
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            if (i==j || i==1)
            {
                a[i][j]=1;
                cout<<a[i][j]<<"\t";
            }
            else
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];
                cout<<a[i][j]<<"\t";
            } 
        } 
        cout<<"\n";
    }  
}
int main()
{
    int n,result;
    cout<<"Enter the number n\n";
    cin>>n;
    pascaltriangle(n);
}*/

#include <iostream>
#include <math.h>
using namespace std;
int fact(int n)
{
    int k=1;
    for (int i = 1; i <= n; i++)
    {
        k=k*i;
    }
    return k;
}
int main()
{
    int n;
    cout<<"Enter the number n\n";
    cin>>n;
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<fact(i)/(fact(i-j)*fact(j))<<"  ";
        }
        cout<<"\n";
    }
}