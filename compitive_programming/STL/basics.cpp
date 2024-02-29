#include <bits/stdc++.h>
using namespace std; 
//c++ defines all its function using namespace std so if we don't write it, 
//we have to declare each time if we will use c++ predefine function

struct student
{
    string name;
    int age;
    char gender;
    bool a;
    student(string s_name,int s_age,char s_gender,bool s_a){
        name = s_name;
        age = s_age ;
        gender = s_gender;
        a = s_a;
    }
};

void print(student &s1){
    cout<<s1.name<<endl;
    cout<<s1.age<<endl;
    cout<<s1.gender<<endl;
    cout<<s1.a<<endl;
}

namespace sumit {
    int val = 20;
}

int main(){
    int val = 10;
    cout<<val<<endl;
    cout<<sumit::val<<endl; //operated using namespace sumit
    
    //wrong way of defining
    // student s1;
    // s1.name = "sumit";
    // s1.age = 12;
    // s1.gender = 'm';
    // s1.a = true;
    // print(s1);

    //if you created consrructor then previous defined is not working see...........
    //create a construtor like thing so that easy and fastly you can make an object
    student s2 ("asmit",10,'m',true);
    print(s2);
    

}