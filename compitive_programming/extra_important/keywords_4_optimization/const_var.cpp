#include <bits/stdc++.h>
using namespace std;

int main(){
    int i = 10; //having r and w access
    int &k = i;//i gives k both r and w access
    k++;
    cout<<k<<endl;

    // int const q; //store garbage in some compiler
    // cout<<q<<endl;
    //q=10; //we can't do

    //same thing
    int const p = 11; //same thing
    const int p1 = 11; //must given the value at the time of initialization

    //const reference from non const var

    int j = 11; // having r and w access
    const int &m = j; //dure to const w path gets blocked, j can only be able to give r path
    //m++; //can't be done 
    j++;
    cout<<m<<endl;
    cout<<j<<endl;

    //const ref from const var
    int const i1 = 10;
    const int &k2 = i1;//both have only r access

    // ref from const var
    int const l = 10; //having only r access
    // int &k = l; //can't give the access of w and can't be equalize
    // cout<<++k<<endl;



}