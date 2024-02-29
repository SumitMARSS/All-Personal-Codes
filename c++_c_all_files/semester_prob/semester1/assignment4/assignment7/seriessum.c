#include <stdio.h>
int main()
{
    int n,i,f=1,j=-1,k=1,p;//assigning variable
    float t,s,sum=0;//assigning real variable
    printf("Enter the number upto which you want to sum series:");
    scanf("%d",&n);//taking input you want series
        for ( i = 1; i <=n; i++)//logics for proceeding series
            {
            k=1;
            for ( p = 1; p <=i; p++)//logics for num^num value
            {
                k=k*i; //multiple times multiply
            }
                f=f*(i+1);//for factorial in series
                s=(float)(i+f)/k;//series value without -ve
                j=j*(-1);//for -ve
                t=s*j;//alternative -ve sign
                sum=sum+t;//getting sum of the series
            }
    printf("The sum of series upto that number is: %f",sum);//printing result
    return 0;
}
