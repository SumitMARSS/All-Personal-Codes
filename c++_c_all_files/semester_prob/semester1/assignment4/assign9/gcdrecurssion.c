#include <stdio.h>
int gcd();//just to declare user function
int main()
{
    int a,b;//defining integer value
    printf("Enter first numbers for finding GCD\n");
    scanf("%d",&a);//taking input from user the first number
    printf("Enter second numbers for finding GCD\n");
    scanf("%d",&b);//taking input from user the second number
    gcd(a,b);//calling user defined function
    return 0;//end
}
int gcd(int a,int b)//user defined function defination
{
    int r;//defining value
    r=a%b;//remainder value
    if (r==0)//if reminder=0
    {
        printf("The GCD for given numbers are %d",b);//printing the gcd value
    }
    else
    {
        return gcd(b,r);//calling user function again 
    }
}