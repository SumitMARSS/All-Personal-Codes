#include <stdio.h>
void before ();
void after ();
int main()
{int a,b;
printf("Enter the first number \n");
scanf("%d",&a);
printf("Enter the second number \n");
scanf("%d",&b);
before (a,b);
after (a,b);
return 0;
}
void before (int a, int b)
{
    printf("Before swapping the number is %d,%d\n",a,b);
}
void after (int a, int b)
{
    a=a^b;
    b=a^b;
    a=a^b;
    printf("After swapping the number is %d,%d\n",a,b);
}




