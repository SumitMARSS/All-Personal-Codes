#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    string s = "thiruvananthapuram";
    unordered_map<char,int>map;
    for(int i=0; i<s.length(); i++){
        map[s[i]]++;
    }
    for(auto i: map){
        cout<<i.first<<" -> "<<i.second<<endl;
    }
}