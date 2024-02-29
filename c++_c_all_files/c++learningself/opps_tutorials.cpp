#include <iostream>
#include<string.h>
#include <bits/stdc++.h>
using namespace std;
class student
{
   public:
   
   string name;
   int age;
   bool gender;
   int printinfo()
   {
      cout<<"\nName  -";
      cout<<name<<endl;
      cout<<"\nAge  -";
      cout<<age<<endl;
      cout<<"\nGender  ";
      cout<< gender<<endl;
      return 0;
   }
   student(){
      cout<<"Default constructor"<<endl;
   }//default constructor
   student(string s, int age1, int g)
   {
      cout<<"parametrised constructer \n";
      name=s;
      age=age1;
      gender=g;

   }//parametrised constructor
   student(student &a)
   {
      cout<<"copy constructer"<<endl;
      name= a.name;
      age=a.age;
      gender=a.gender;
   }//copy constructer
   ~student(){
      cout<<"Destructor\n"<<endl;
   }
   //operator overloading to overcome the situation that directly not comparing
   bool operator == (student &a){
      if (name==a.name,age==a.age,gender==a.gender)
      {
         return true;
      }
      else
      {
         return false;
      } 
   }
};

int main()
{
   /*
   student a;
   cout<<"Name  -";
   string s;
   cin>>s;
   a.setname(s);
   cout<<a.getname();
   cout<<"Age  -";
   cin>>a.age;
   cout<<"Gender  -";
   cin>>a.gender;
   cout<<a.printinfo();
   student b ("sumit",20,1);
   cout<<b.printinfo();
   student c;*/
   student a("sumit",20,1);
   cout<<a.printinfo();
   cout<<"\n\n";
   student b;
   cout<<b.printinfo();
   cout<<"\n\n";
   student c=a;
   cout<<c.printinfo();
   cout<<"\n\n";
   if (a==c)
   {
      cout<<"same"<<endl;
   }
   else
   {
      cout<<"not same"<<endl;
   }
}