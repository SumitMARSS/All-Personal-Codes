#include <stdio.h>
int main()
{
    int n,r,x,sum=0,a,fac=1,i;//defining variables
    printf("Enter the number for check Krishnamurthy number:");
    scanf("%d",&n);//taking input for checking the number
    a=n;//using other value so than the value of n do't change
    if (n<=0)
    {
        printf("INVAILID INPUT");
        return 0;
    }
    while (a>0)//condition for last entry
    {
        r=a%10;//for remainder or last digit
        x=a/10;//getting other digits
        fac=1;//going in loop giving value again 1 to fact
        for ( i = 1; i <=r; i++)//condition for calculating factorial
        {
            fac=fac*i;//calculating factorial
        }
        sum=sum+fac;//getting the sum
        a=x;//changing the value of quotient to number
    }
    if (sum==n)//condition for Krishnamurthy number
    {
        printf("\nThis is Krishnamurthy number");//printing output
    }
    else
    {
        printf("\nThis is not Krishnamurthy number");//printing output
    }
    return 0;//end
}