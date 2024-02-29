#include <stdio.h>
void palindrome();//just to declare user function

int main()
{int n;//defining value
printf("Enter any number you want to check\n");
scanf("%d",&n);//taking input from user
palindrome(n);//calling user defined function
return 0;  
}
void palindrome(int n)//user defined function defination
{int t,sum=0,r;
    t=n;
while (t!=0)
{
    r=t%10;//remainder value
    sum=sum*10+r;//geeting reverse value as loop last
    t=t/10;
} 
if (sum==n)//condition for palindrome
{
    printf("The number is palindrome");//printing the result
}
else
{
    printf("The number is not palindrome");//printing the result
}}