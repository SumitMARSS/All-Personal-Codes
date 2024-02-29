#include <iostream>
#include <math.h>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//vector play
/*
int main()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    /*
    //1st way to iterate
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    */
    //2 nd way to iterate
    /*
    vector<int>::iterator it;
    for ( it = v.begin(); it!=v.end() ; it++) //it is a pointer
    {
        cout<<*it<<endl;
    }
    
   //3rd way
   
   for (auto element :v)
   {
        cout<<element<<endl;
   }
   v.pop_back();
   for (auto element :v)
   {
        cout<<element<<endl;
   }
   vector <int> v2 (3,32); //taking in a line if same numbers are there
   for (auto element :v2)
   {
        cout<<element<<endl;
   }
   swap(v,v2);//swapping vectors
   for (auto element :v)
   {
        cout<<element<<endl;
   }
   for (auto element :v2)
   {
        cout<<element<<endl;
   }
}
*/
////vector pair play
//use of pairs
bool mycompare(pair<int,int>p1, pair<int,int>p2)
{
    return p1.first<p2.first;
}

int main()
{
    int arr[] = {10,16,7,14,5,3,12,9};
    vector < pair < int, int >> v;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        v.push_back(make_pair(arr[i],i));
    }
    sort(v.begin(),v.end(), mycompare);
    for (int i = 0; i < v.size(); i++)
    {
        arr[v[i].second] = i;  //assigning the index of sorted array 0,1,2.....
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout<<arr[i]<<endl;
    }
}