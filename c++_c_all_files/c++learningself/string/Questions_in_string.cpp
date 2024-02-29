#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
//using logics
int main()
{
    //string s1="sdkhfakhgheiu";//for small to capital
    string s1="AHFEIHOWHUBHI";//for capital to small
    //cout<<'s'-'S'<<endl;
    //cout<<'a'<<endl;
    //string s1;
    //cin>>s1;
    int i=0;
    while (1)
    {
        if (s1[i]>='a' && s1[i]<='z')
        {
            s1[i]=s1[i]-32;
            i++;
            if (s1[i]=='\0')
            {
                break;
            }
        }
        else if (s1[i]>='A' && s1[i]<='Z')
        {
            s1[i]=s1[i]+32;
            i++;
            if (s1[i]=='\0')
            {
                break;
            }
        }
    }
    cout<<s1<<endl;
    return 0;
}
*/
//using function in string
/*
int main()
{
    string s1="sdkhfakhgheiu";
    transform(s1.begin(),s1.end(),s1.begin(),:: toupper);
    cout<<s1<<endl;
    transform(s1.begin(),s1.end(),s1.begin(),:: tolower);
    cout<<s1<<endl;
}
*/
///for count of repeated alphabets
int main()
{
    string s1;
    cin>>s1;
    //sort(s1.begin(),s1.end(),greater<int>());   //sorting string in decending order
    int fre[26];
    for (int i = 0; i < 26; i++)
    {
        fre[i]=0;
    }
    for (int i = 0; i < s1.size(); i++)
    {
        fre[s1[i]-'a']++;
    }
    int ans,i;
    char alphabet;
    ans=0;
    for (int i = 0; i < 26; i++)
    {
        if (ans<=fre[i])
        {
            ans=fre[i];        //for max frequency
            alphabet=i+'a';  //for alphabet
        }
    }
    cout<<ans<<"\n"<<alphabet<<endl;
}