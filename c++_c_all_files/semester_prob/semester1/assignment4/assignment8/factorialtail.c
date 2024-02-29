#include <stdio.h>
int fact();//declaring the user defined function
int main()
{
    int n,p;//assigning the variable
    printf("Enter the number:");
    scanf("%d",&n);//taking input
    if (n>=0)//for number greater than 0
    {
        p = fact(n);//calling function
        printf("The factorial of the number is :%d",p);//printing the result
    }
    else
    {
        printf("INVALID INPUT");//invalid condition
    }
    return 0;
}
int fact(int n)//defining the function
{
    if (n==0||n==1)//terminating condition
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);//recalling the function
    }
}