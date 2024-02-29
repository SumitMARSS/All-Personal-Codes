#include <bits/stdc++.h>
using namespace std;
//start as a default argu
int sum(int a[],int size,int start = 0){
    int sum=0;
    for (int i = start; i < size; i++)
    {
        sum += a[i];
    }
    return sum;
}
//b,c,d as a default argu
inline int sum2(int a,int b=0,int c=0,int d=0){
    return a+b+c+d;
}

int main(){
    int a[6] = {1,2,3,4,5,6};
    int p=1,q=2,r=3,s=4;
    //effectively 2 functions are made
    cout<<sum(a,6,2)<<endl;
    cout<<sum(a,6)<<endl;
    //effectively 4 functions are made
    cout<<sum2(p)<<endl;
    cout<<sum2(p,q)<<endl;
    cout<<sum2(p,q,r)<<endl;
    cout<<sum2(p,q,r,s)<<endl;
}