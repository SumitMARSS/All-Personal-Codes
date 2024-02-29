#include <bits/stdc++.h>
using namespace std;

int main(){
    int t = 65;
    char c = t;//implicit typecasting
    int *p = &t;
    //char *pc = p; //showing error as character pointer can't be equalize as int *
    char *pc = (char *)p; //explicit typecasting
    cout<<c<<endl;
    cout<<p<<endl;
    cout<<pc<<endl;//do to address and print until it finds null character
    cout<<*pc<<endl;//little endian system
    cout<<*p<<endl;
    cout<<*(pc+1)<<endl;
    cout<<*(pc+2)<<endl;
    cout<<*(pc+3)<<endl;

    // char ch[4] = {'a','b','c','d'};
    // int *ptr = (int *) ch;
    // cout<<&ch[0]<<endl;
    // cout<<ptr<<endl;
    // cout<<*ptr<<endl;//undefined behaviour
    string str = "abcd";
    string * str1 = &str;
    cout<<str1<<endl;
}