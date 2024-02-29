#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cout<<"Your string is: ";
    cin>>str;
    int n = str.length();


    //i <= n/2 it will create problem with mid char as it swap itself with itself result error
    for (int i = 0; i < n/2; i++) 
    {
        swap(str[i],str[n-i-1]);
    }


    // int start=0;
    // int end=s.size()-1;
    // while(start < end){
    //     swap(s[start++],s[end--]);
    // }

    cout<<"Your reversed string is: "<<str<<endl;
    reverse(str.begin(),str.end());

    cout<<"Your again reversed string is: "<<str;
}