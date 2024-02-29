//what are references??
//they don't have their own memory space, they use others memory space whcih memory is already existing
//if you makes changes in one others will be changed automatically
//uses->   1.send into function as an argument ,2. No new memory will be created, using the same memory 


#include <bits/stdc++.h>
using namespace std;
//because of this changes will not happen until we use reference variable
void increment(int n){ //because here we are creatinga new memory and we update in that memory
    n++;
}
//here we are not making any new memory just reference the memory of i,using the same memory 
//so that if we do any changes then it will also reflect in main function
void increment1(int &n){
    n++;
}

int main(){
    int i = 10;//memory get allocated on a particular address
    int &j = i;//memory will not be allocated only reference to that memory is given
    increment(i);//no changes
    cout<<j<<endl;
    cout<<i<<endl;
    increment1(i);//changes reflect
    cout<<j<<endl;
    cout<<i<<endl;
    i++;
    //changes gets reflected in both i and j this is because both i and j are accessing same address
    //address of i gets referenced in address of j
    cout<<j<<endl;
    cout<<i<<endl;
    j++;
    cout<<j<<endl;
    cout<<i<<endl;
    int k=100;
    j=k;
    cout<<j<<endl;
    cout<<i<<endl;
    //what is the use of this??

}
