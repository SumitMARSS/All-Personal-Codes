#include <stdio.h>

int main()
{int a,b,t;
printf("Enter the number a ,b\n");
scanf("%d,%d",& a,& b);
a=a^b^(b=a);
printf("%d,%d",a,b);
return 0;
}