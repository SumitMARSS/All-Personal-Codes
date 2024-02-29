#include <bits/stdc++.h>
using namespace std;
//redability improves but their is some impact on performance as 
//main has to stop if we have to read other function
//make function inline so that compiler can read the code without seeing any function

//what inline do??    
//paste the line of code in the main func so that 
//compiler can't have to visit other function but only for small function like 2-3 line of code atmost
inline int max(int a,int b){
    return (a>b) ? a : b;
}

int main(){
    int a=2, b=3,x=22,y=21;
    int c = max(a,b);
    int z = max(x,y);
    cout<<c<<" and "<<z<<endl;
}


//replacement is given upper

/*
int main(){
    int a=2,b=5;
    int c ;
    //for max 6 line of code replace it with tertiary operator
    if(a>b){
        c = a;
    }
    else
    {
        c=b;
    }
    cout<<c<<endl;
    int max = (a>b) ? a : b; //check condition and return a if true else b
    cout<<max;
    int x=20,y=22;
    int max1 = (x>y) ? x : y;
    cout<<max1<<endl; //here we are using tertiary operator again and again not too much readable
}
*/
