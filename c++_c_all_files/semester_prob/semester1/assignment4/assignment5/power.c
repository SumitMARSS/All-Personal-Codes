#include <stdio.h>

int main()
//defining inputs
{int a,b,i,p=1;
//taking input of a and b
printf("Enter the value of a :\n",a);
scanf("%d",&a);
printf("Enter the value of b :\n",b);
scanf("%d",&b);
//logic for multiplying multiple times
for ( i = 0; i <b; i++)
{
    p=p*a;
}
//printing final result
printf("The value of %d ^ %d is %d",a,b,p);

return 0;
}