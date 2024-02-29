#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v = {1,2,3,4,5};
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

//some important keywords
    auto i = 1.0; //auto detect the datatype


//new method syntex

    //range based loop
    //if & is used then actual values of arrays are used //used as reference
    for (auto &i : v)
    {
        cout<<i<<endl;
    }

    //here copy of array is used in i
    // for (auto i : v)
    // {
    //     cout<<i<<endl;
    // }

    //small line of codes
    vector<pair<int,int>> v_p1 = {{1,2},{2,3},{3,4}};
    //use of auto, no need to declare vector<pair<int,int>> as datatype
    for (auto &i : v_p1)
    {
        cout<<i.first <<" "<<i.second<<endl;
    }
    


//old method iterators

    // //simple iterators

    vector <int> :: iterator it = v.begin();
    // cout<<(*it)<<endl;
    // cout<<(*(it+2))<<endl; //act like pointers

    for (it = v.begin(); it!= v.end(); it++)
    {
        cout<<(*it)<<endl;
    }

    //iterators on vector pair

    vector<pair<int,int>> v_p = {{1,2},{2,3},{3,4}};

    vector<pair<int,int>> :: iterator it1; //no need of this line just declare auto infront of it1 in for loop

    for (auto it1 = v_p.begin(); it1 != v_p.end(); it1++)
    {
        cout<< (*it1).first <<" "<< (*it1).second<<endl;
    }
    for ( it1 = v_p.begin(); it1 != v_p.end(); it1++)
    {
        cout<< it1->first <<" "<< it1->second <<endl;
    }
    
}