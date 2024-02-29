#include <bits/stdc++.h>
using namespace std;

//iterative approch


//Recursive approch
int fast_expo(int a,int b){
    if (b==0)
    {
        return 1;
    }
    if (b==1)
    {
        return a;
    }
    if (b%2 == 0)
    {
        b = b/2;
        return fast_expo(a,b)*fast_expo(a,b);
    }
    else
    {
        b = b/2;
        return a*fast_expo(a,b)*fast_expo(a,b);
    }
}

int main(){
    int a,b;
    cout<<"Enter a and b: "<<endl;
    cin>>a>>b;
    cout<<"Recursive approch -> Ans is: "<<fast_expo(a,b)<<endl;
}