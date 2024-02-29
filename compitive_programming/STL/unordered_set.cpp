//q queary and n strings in each quary print yes if string present otherwise no

//order doesn't matter so use unordered set as it time complexity is (o(1)) of insertion or removal
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
        cin>>n;
        unordered_set <string> u_s;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin>>str;
            u_s.insert(str);//O(1)
        }
        u_s.find("ram");//O(1)
    int t;
    cin>>t;
    while (t--)
    {
        string str1;
        cin>>str1;
        if (u_s.find(str1) == u_s.end())
        {
            cout<<"false"<<endl;
        }
        else
        {
            cout<<"true"<<endl;
        } 
    }
}