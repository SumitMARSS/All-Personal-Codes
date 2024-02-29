#include<iostream>
#include<cmath>

using namespace std;

long long power(int n)
{
    long long k=1;
    for(int i=0;i<n;i++)
    {
        k=k*10;
    }
    return k;
}

long numlen (long long t)
{
    long n=0;
    if(n==0)
    {
        return 1;
    }
    while (t>0)
    {
        t=t/10;
        n++;
    }
    return n;
}

long long karatsuba(long long x,long long y){
    long long p,u,v,w,z;
    long n1=numlen(x);
    long n2=numlen(y);
    long long x1,x2,y1,y2;
    long n=max(n1,n2);
    if(n==1)
    {
        p=x*y;
        return p;
    }
    else
    {
        n=n+n%2;
        x2=x%power(n/2);
        x1=x/power(n/2);
        y2=y%power(n/2);
        y1=y/power(n/2);
        x=power(n/2)*x1+x2;
        y=power(n/2)*y1+y2;
        u=karatsuba(x1,y1);
        v=karatsuba(x2,y2);
        w=karatsuba(x1-x2,y1-y2);
        z=u+v-w;
        p=power(n)*u+power(n/2)*z+v;
        return p;
    }
}

int main()
{
    long long int s1,s2,fstr;
    cout<<"Enter the first integer:\n";
    cin>>s1;
    cout<<"Enter the second integer:\n";
    cin>>s2;
    fstr=karatsuba(s1,s2);
    cout<<"Final integer multiplication is:\n";
    cout<<fstr<<endl;
    return 0;
}

/*
//practice try
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
#include <climits>
using namespace std;

long long power(long s)
{
    long long pow =1;
    for (int i = 0; i < s; i++)
    {
        pow = pow * 10;
    }
    return pow;
}

string karatsuba(string s1,string s2)
{
    //string x1,x2,y1,y2;
    string u,v,w;
    long long P;
    long long x,y,x1,x2,y1,y2,z,k,m;
    int n;
    m=s1.size();
    k=(m/2);
    x=strtoull(s1);
    y=strtoull(s2);
    if (m==1)
    {
        n = strtoull(s1) * strtoull(s2) ;
        return to_string(n);
    }
    else
    {
        x = power(k)* x1 + x2;
        y = power(k)* y1 + y2;

        u = karatsuba(to_string(x1), to_string(x2));
        v = karatsuba(to_string(y1), to_string(y2));
        w = karatsuba(to_string(x1-x2),to_string(y1-y2));
        z = strtoull(u) + strtoull(v) - strtoull(w) ;
        P = (power(m) * strtoull(u) + power(k) * z + strtoull(v));
    }
    return int stol(P,10);
}

int main()
{
    string s1,s2,fstr;
    cout<<"Enter the first string:\n";
    cin>>s1;
    cout<<"Enter the second string:\n";
    cin>>s2;
    //making even int
    if ((s1.size() - s2.size()) == 1)
    {
        s2 = "0" + s2 ;
    }
    else if ((s2.size() - s1.size()) ==1)
    {
        s1 = "0" + s1 ;
    }
    else if ((s1.size() == s2.size()) && (s1.size()%2 == 1 ) )
    {
        s1 = "0" + s1 ;
        s2 = "0" + s2 ;
    }
    //cout<<s1<<"\n"<<s2<<endl;
    fstr = karatsuba(s1,s2);
    cout<<"Final string multiplication is:\n";
    cout<<fstr;

}*/