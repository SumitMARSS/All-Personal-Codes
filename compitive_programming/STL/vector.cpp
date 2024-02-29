#include <bits/stdc++.h>
using namespace std;
//we can make string vector also

void printVector(vector <string> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<"v "<<i<<" is: "<<v[i]<<endl;
    }
    cout<<"capacity:"<<v.capacity()<<endl;
    cout<<"size:"<<v.size()<<endl;
}

int main(){
    vector<string>v;
    int n;
    cout<<"Enter the no of str\n";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    printVector(v);
}



/*

//always pass as reference as making copy is too time consuming
void printVector(vector <int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<"v "<<i<<" is: "<<v[i]<<endl;
    }
    cout<<"capacity:"<<v.capacity()<<endl;
    cout<<"size:"<<v.size()<<endl;
}

int main(){
    //local vector array, we can't declare an array size more then 10^5 and globally 10^7
    //limitation on contiguous memory allocation
    vector<int>v;
    //vector<int>v1(10,3); //initially fill the value
    int n;
    cout<<"Enter the no of array you want:"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
        
    }
    printVector(v);
    //printVector(v1);
    v.pop_back();//last elements are get poped //o(1)
    vector<int>v2 = v; //we can copy the array  o(n) same as for loop
    printVector(v);
    printVector(v2);
    v2.push_back(10);
    printVector(v);
    printVector(v2);
    //arrays are allocated like if 4 arrays are there and 1 are deleted 3 if we need more get double ->6
}



*/

