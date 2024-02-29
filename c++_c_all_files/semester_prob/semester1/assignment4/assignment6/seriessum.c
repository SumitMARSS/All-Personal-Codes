#include <stdio.h>
#include <math.h>
void series(int n)//declare and define the user function
{int i;
float s,d=0,t;//defining value
if (n==0)//conditon if n=0
{
    printf("0 is the output");//printing the result
}
else if (n>0)//conditon for n>0
{
for ( i = 1; i <=n; i++)//loop for continue the sum
{
    s=(float)1/i;//taking denominator value
    t=pow(s,i);//giving the power
    d=d+t;//adding all the result
}
printf("The sum of the series upto %d is %f",n,d);//printing the result
}
else
{
    printf("INVALID INPUT");//printing the result
}
}
int main()
{int n;
printf("Enter the term you want to calculate series sum\n");
scanf("%d",&n);//taking input from user
series (n);//calling user defined function
return 0;
}