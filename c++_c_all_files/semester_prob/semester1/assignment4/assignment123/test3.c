#include <stdio.h>

int main()
{int n,j,i,s;
printf("Enter the number:\n");
scanf("%d",&n);
s=0 ;
j=1;
for ( i =1; i <=n; i++)
{
    s=s+(i*j);
    j=j*(-1);
}
printf("%d",s);
return 0;
}