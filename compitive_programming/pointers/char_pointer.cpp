#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1,2,3};
    char c[] = "abc";
    cout<<a<<endl;
    cout<<c<<endl; //here we feel like we get address but we get char array value
    char *cp = &c[0];
    cout<<cp<<endl; //here also we get char array value -> abc

    char c1 = 'a';
    char *c2 = &c1;
    cout<<c1<<endl;
    cout<<"hjergj"<<endl;
    cout<<c2<<endl; //here it will print until we don't get /0
    cout<<&c2<<endl;

    //important point what is the diff btw below 2 lines
    // char str[] = "abcsdf";  //value will get copy in memory from temporary memory
    // char *ptr = "abcsdf";  //value is pointing towards temporary memory may get sometime error if we have 
    //only read optionss so better to use str array or the first case 
}