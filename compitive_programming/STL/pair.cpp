#include <bits/stdc++.h>
using namespace std;

int main(){
    //pair of int and char
    pair<int,char> p;
    cout<<"Enter 1st int and then char as a pair"<<endl;
    cin>>p.first>>p.second;
    cout<<p.first<<" "<<p.second<<endl;
    //reference var of pair
    pair<int,char> &p3 = p;
    cout<<p3.first<<" "<<p3.second<<endl;
    //pair of int and string
    pair<int,string> p2;
    p2 = {10,"sumit"};
    cout<<p2.first<<" "<<p2.second<<endl;

    //array in pair
    pair<int,int> p_arr[3];
    cout<<"Enter the elements in array\n";
    for (int i = 0; i < 3; i++)
    {
        cin>>p_arr[i].first>>p_arr[i].second;
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<p_arr[i].first<<" "<<p_arr[i].second<<endl;
    }
    //relations are maintained if you do any kind of operation
    swap(p_arr[1],p_arr[2]);
    cout<<"Array after swap"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout<<p_arr[i].first<<" "<<p_arr[i].second<<endl;
    }
    
}

