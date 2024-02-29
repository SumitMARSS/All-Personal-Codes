#include <bits/stdc++.h>
using namespace std;
//very risky to use
int a; //global variable, any func can access this variable, access to whole program

void g(){
    a++; //12
    cout<<++a<<endl; //13 //15
}

void f(){
    a++;
    cout<<a<<endl; //11
    g();
}

int main(){
    a = 10;
    f();
    g();
    return 0;
}