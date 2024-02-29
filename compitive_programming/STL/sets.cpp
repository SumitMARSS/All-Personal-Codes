#include <bits/stdc++.h>
using namespace std;

//multiset
int main(){
    multiset<string> s ={{"sumit"},{"abc"},{"ram"},{"shyam"},{"abc"}};
    // int n;
    // cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     string str;
    //     cin>>str;
    //     s.insert(str);//log(n)
    // }

    //try from 18-22

    // auto it = s.find("abc"); //find sumit in sets  (log(n))
    // //erase if not found until end
    // if(it != s.end()){
    //     s.erase(it); //erase only one having first it value
    // }

    //try from 24 comment 17-21
    //internally erase function also find it value untill it get s.end()
    //s.erase("abc"); //erase all abc from multisets

    //sets print in order and have unique elements in it
    for (auto &i : s)
    {
        cout<<i<<endl;
    }
    
}


//ordered_set

// int main(){
//     set<string> s;
//     int n;
//     cin>>n;
//     for (int i = 0; i < n; i++)
//     {
//         string str;
//         cin>>str;
//         s.insert(str);//log(n)
//     }
//     auto it = s.find("sumit"); //find sumit in sets  (log(n))
//     //erase if not found until end
//     if(it != s.end()){
//         s.erase(it);
//     }


//     //sets print in order and have unique elements in it
//     for (auto &i : s)
//     {
//         cout<<i<<endl;
//     }
    
// }