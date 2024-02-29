#include <stdio.h>

int main()
{
int n,a=0,b=1,c=0,x,d;
printf("Enter the number of terms:");
scanf("%d",&n);

while(c<=n)
{
c=a+b;
a=b;
b=c;
d=a+b;

for(x=c+1;x<d;x++)
{
if(x<=n)
{
    printf("%d",x);
}
else
{
    break;
}
}
}

return 0;
}