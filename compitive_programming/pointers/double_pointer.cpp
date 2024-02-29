#include <bits/stdc++.h>
using namespace std;

void increment1(int **p){ //not change
    p = p+1;
}
void increment2(int **p){ //change
    *p = *p +1;
}
void increment3(int **p){  //change
    **p = **p +1;
}

int main()
{
    int i = 10;
    int *p = &i;
    int* *p2 = &p; //storing address of pointer

    cout<<p<<endl;
    cout<<&i<<endl;
    cout<<*p2 <<endl; //p2 derefrence the value in p

    cout<<&p<<endl;
    cout<<p2<<endl;//p2 store the address of p

    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**p2<<endl;


}