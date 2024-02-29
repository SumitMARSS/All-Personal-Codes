#include <iostream>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a,b,sum,amo,c;//initialising integer variable
    cout<<"Hello world\n";
    /*cout<<"Enter the amount1 given:\n";//same as printf
    cin>>a;//used only to take input same as scanf
    cout<<"Enter the amount2 given:\n";
    cin>>b;
    sum=a+b;
    cout<<"Sum of the amount you given is:\n";
    cout<<sum;*/
    cout<<"Enter your num1:";
    cin>>a;
    cout<<"Enter your num2:";
    cin>>b;
    cout<<"Enter your num3:";
    cin>>c;
    if(a>b)
    {
        //cout<<"Any girlfrined";
        if (a>c)
        {
            cout<<a;
            cout<<" is greatest\n";
        }
        else if (a==c)
        {
            cout<<a;
            cout<<"is greatest but num1 and num 3 is same greater than num 2\n";
        }
        else
        {
            cout<<c; 
            cout<<" is greatest\n";
        }
    }
    else
    {
        //cout<<"Friends";
        if (b>c)
        {
            cout<<b;
            cout<<" is greatest\n";
        }
        else if (b==c)
        {
            cout<<b;
            cout<<"is greatest but num1 and num 3 is same greater than num 2\n";
        }
        else
        {
            cout<<c; 
            cout<<" is greatest\n";
        }
    }
    
    return 0;
}