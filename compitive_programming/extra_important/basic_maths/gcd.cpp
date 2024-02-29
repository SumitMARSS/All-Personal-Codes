#include <bits/stdc++.h>
using namespace std;

//iterative approch
int gcd_iter(int a, int b){
    if (a==0)
    {
        return b;
    }
    if (b==0)
    {
        return a;
    }
    while (a != b)
    {
        if (a > b)
        {
            a = a-b;
        }
        else
        {
            b = b-a;
        }
    }
    return a;
}

//recursive approch
//sub rule
int gcd(int a,int b){
    if (a == b) {
        return a;
    } else if (a > b) {
        return gcd(a - b, b);
    } else {
        return gcd(a, b - a);
    }
}
//div rule
int gcd1(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main(){
    int a,b;
    cout<<"Enter 2 numbers: "<<endl;
    cin>>a>>b;
    cout<<"Sub rule recur-> "<<gcd(a,b)<<endl;
    cout<<"Div rule recur-> "<<gcd1(a,b)<<endl;
    cout<<"Sub rule iterative approch -> "<<gcd_iter(a,b)<<endl;

}