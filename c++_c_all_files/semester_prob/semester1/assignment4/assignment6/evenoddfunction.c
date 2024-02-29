#include <stdio.h>
void check();
int main()
{int a;
printf("Enter any number");
scanf("%d",&a);
check(a);
return 0;
}
void check(int a)
{if (a%2==0)
{
      printf("The given number %d is even",a);
}
else
{
      printf("The given number %d is odd",a);
}
}