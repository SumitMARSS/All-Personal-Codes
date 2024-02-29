#include <stdio.h>

int main()
{int a,b,r,LCM,c;
//for taking input//
printf("Enter the value of a\n");
scanf("%d",&a);
printf("Enter the value of b\n");
scanf("%d",&b);
//logics for hcf//
while (a%b!=0)
{
    c=a*b;
    r=a%b;
    a=b;
    b=r;
}
//for printing the value of hcf//
printf("HCF is %d\n",b);
//formula to find lcm//
LCM=c/b;
//for printing the value of lcm//
printf("LCM is %d",LCM);
return 0;
}