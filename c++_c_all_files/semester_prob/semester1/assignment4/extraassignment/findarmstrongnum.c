#include <stdio.h>
int main()
{
    int n,num1,cub,x,sum=0,a;//defining inputs
    printf("Enter the number for check:");
    scanf("%d",&n);//taking input for checking the number 
    a=n;//using other value so than the value of n do't change
    while (a>0)//condition for last entry
    {
        num1=a%10;//for remainder or last digit
        x=a/10;//getting other digits
        cub=num1*num1*num1;//cubing the number
        sum=sum+cub;//getting all sum
        a=x;//changing the value of quotient to number
    }
    if (sum==n)//condition for Armstrong number
    {
        printf("This is an armstrong number");//printing output
    }
    else
    {
        printf("This is not an armstrong number");//printing output
    }
    return 0;//end
}
