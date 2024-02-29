#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<string, int> mapp;
    //insertion
    //1.
    mapp["sumit"] = 5;
    //2.,3,4
    pair<string,int>p = {"asmit",6};
    pair<string,int>p1 = make_pair("raj",60);
    pair<string,int>p3("rahul",8);
    mapp.insert(p);
    mapp.insert(p1);
    mapp.insert(p3);

    //searching
    cout<< mapp.at("asmit")<<endl;
    //or
    cout<<mapp["raj"]<<endl;
    //but if we search for an entry which doesn't exist
    // cout<< mapp.at("ram")<<endl;    //-> doesn't show any entry for ram as show error 
    cout<<mapp["ram"]<<endl;    // create an entry for ram and map with 0 -> {ram,0}
    cout<< mapp.at("ram")<<endl;    //check in line no 26 and 27 main difference
    ///////////see up 26,27 diff
    //size
    cout<<" size of mapp -> "<<mapp.size()<<endl;

    //count used to check wheather a key is present in mapp or not
    cout<<" count of ram -> "<<mapp.count("ram")<<endl;
    cout<<" count of hero -> "<<mapp.count("hero")<<endl;

    //erase
    mapp.erase("ram");
    cout<<"After erase size is "<<mapp.size()<<endl;


    // for access whole loop in a continuity
    //1. using for loop
    cout<<" ITERATORS ARE: "<<endl;
    for(auto i: mapp){
        cout<<"key -> "<<i.first<<" "<<" value-> "<<i.second<<" "<<endl;
    }
    //2. using iterator
    unordered_map<string, int> :: iterator it = mapp.begin();
    while (it != mapp.end())
    {
        cout<<it->first<<" "<<it->second<<" "<<endl;
        it++;
    }
    return 0;
    


}