#include <stdio.h>

int main()
{int a,b,t;
printf("Enter the number a ,b\n");
scanf("%d,%d",& a,& b);
t=a;
a=b;
b=t;
printf("%d,%d",a,b);
return 0;
}