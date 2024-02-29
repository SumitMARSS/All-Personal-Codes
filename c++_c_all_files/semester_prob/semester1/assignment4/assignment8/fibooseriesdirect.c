#include <stdio.h>
int fiboo();//declaring the user defined function
int main()
{
    int n,a=0,b=1;//assigning the variable
    printf("Enter the number upto which you want fiboo series:");
    scanf("%d",&n);//taking input for number of variables you want to print in fiboo series
    printf("The fiboo series is :\n");
    fiboo(a,b,n);//calling the user defined function
    return 0;
}
int fiboo(int a, int b, int n)//defining the user defined function
{
    if (n==0)//terminating the user defined function
    {
        return 0;
    }
    else
    {
        printf("%d\n",a);//printing the result again whenever function is call
        return fiboo(b,a+b,n-1);//again calling the function 
    }
    
}