#include <stdio.h>

int main()
{int a,c,i=1,numdig,k=1,b=0,j=1;
printf("Enter the value of a\n");
scanf("%d",&a);
c=a;
while (c!=0)
{
    c/=10;
    numdig=i;
    i++;
}
while (k<=numdig)
{
    b=b+7*j;
    j=j*10;
    k++;
}
if (a<=b)
{
    printf("The consecutive of 7's is %d-%d=%d",b,a,b-a);
}
else
{
    printf("INVALID INPUT");
}
return 0;
}