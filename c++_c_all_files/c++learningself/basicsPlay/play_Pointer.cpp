#include <iostream>
#include <math.h>
#include <climits>
using namespace std;

/*
//play with pointer
int main()
{
    int n=10;
    int *ptr;
    ptr=&n;
    int **ptr1;
    ptr1=&ptr;
    cout<<*ptr<<endl;
    cout<<ptr<<endl;
    cout<<*ptr1<<endl;
    cout<<**ptr1<<endl;
    cout<<ptr1<<endl;
}
*/
//call with reference
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int a=2,b=3;
    swap(&a,&b);
    cout<<a<<" "<<b<<endl;
}