#include <bits/stdc++.h>
using namespace std;

//vectors of vectors

void printVec(vector <int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"size and capacity is:"<<v.size()<<" "<<v.capacity()<<endl;
}

int main(){
    int n;
    //no of rows are dynamics and columns are in vector space (dynamics)
    cout<<"Enter no of vectors"<<endl;
    cin>>n;
    vector<vector<int>>v;
    for (int i = 0; i < n; i++)
    {
        //initial we have 0 size of v
        int ele_in_vec;
        cout<<"Enter elements in vector"<<endl;
        cin>>ele_in_vec;
        vector <int> temp1;
        //v.push_back(vector<int>());
        for (int j = 0; j < ele_in_vec; j++)
        {
            int val;
            cout<<"Enter val of each elements in v[i] "<<endl;
            cin>>val;
            temp1.push_back(val);
            //v[i].push_back(val)
        }
        v.push_back(temp1);
    }
    v[0].push_back(12); // we only push back if we have created that vector
    v.push_back(vector<int>()); //pushing an empty vector can be used in line 27 and directly push v[i].push_back(val) 
    for (int i = 0; i < v.size(); i++)
    {
        printVec(v[i]);
    }
}


/*
//array of vector 

void printVec(vector <int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    //no of rows are fixed and columns are in vector space (dynamics)
    cout<<"Enter no of vectors"<<endl;
    cin>>n;
    vector<int>v[n];
    for (int i = 0; i < n; i++)
    {
        int ele_in_vec;
        cout<<"Enter elements in vector"<<endl;
        cin>>ele_in_vec;
        for (int j = 0; j < ele_in_vec; j++)
        {
            int val;
            cout<<"Enter val of each elements in v[i] "<<endl;
            cin>>val;
            v[i].push_back(val);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printVec(v[i]);
    }
}

*/









/*
//vector of pair
void printvec(vector<pair <int,int> > &v){
    for (size_t i = 0; i < v.size(); i++)
    {
        cout<<v[i].first<<" and "<<v[i].second<<endl;
    }
    
}

int main(){
    vector <pair <int,int> >v; 
    int n;
    cout<<"Enter the n";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y}); //pair can also be created by make_pair(x,y)
    }
    printvec(v);
}
*/

