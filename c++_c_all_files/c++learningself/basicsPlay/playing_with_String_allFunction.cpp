#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
//input  output  snetense
int main()
{
    string str;
    cin>>str;//taking input
    //getline(cin,str);//for taking input the sentence
    cout<<str;//giving output

}*/
/*
//append
int main()
{
    string s1="fam";
    string s2="ily";
    //cout<<s1+s2<<endl;       //1. way
    //s1.append(s2);
    //cout<<s1<<endl;         //2. way
    //s1=s1+s2;              //3. way
    cout<<s1<<endl; 
}*/

//clear string
/*
int main()
{
    string str="bhdkjehe hfeihiu iehihi";
    cout<<str<<endl;
    str.clear();
    cout<<"words appears here after if it is there\n";
    cout<<str<<endl;
    string s1="786";
    int x = stoi(s1);    //string to int
    x=x+2;
    cout<<x<<endl;
    
    //int x=786;
    //cout<<to_string(x)+'2'<<endl;//int to string
}*/

//compare of strings
/*
int main()
{
    string s1="abc";
    string s2="xyz";
    
    //cout<<s1.compare(s2)<<endl;   //giving -1 output as s1 is lesser then s2
   //cout<<s2.compare(s1)<<endl;   //giving +ve(1) output as s2 is gretaer then s1
   
   if (s1.compare(s2))
   {
        cout<<"strings are unequal";
   }
   else
   {
        cout<<"\nEqual strings";
   }
   if (!s2.compare(s1))
   {
        cout<<"Equal strings";
   }
}*/
/*
//empty function check
int main()
{
    string s1="abc";
    cout<<s1<<endl;
    s1.clear();
    if (s1.empty())
    {
        cout<<"String is empty\n";
    }
}*/


//some function
/*
int main()
{
    string s1="nincompoop";
    cout<<s1<<endl;
    //s1.erase(3,3);//erase
    //cout<<s1.find("po")<<endl;// find fun     return the index of start
    //s1.insert(3,"sumit");//from where to insert and what to insert
    //cout<<s1.length()<<endl;
    //cout<<s1.size()<<endl;   //find length of string
    string s2=s1.substr(6,4);   //substring print
    cout<<s2<<endl;
}*/
/*/
int main()
{
    string s1="nincompoop";
    cout<<s1<<endl;
    //accessing each alpha
    for (int i = 0; i < s1.length(); i++)
    {
        cout<<s1[i]<<endl;
    }
}/*/
int main()
{
    string s1="sdkhfakhgheiu";//#include algo is needed for sorting
    sort(s1.begin(),s1.end());//sorting
    cout<<s1<<endl;
}