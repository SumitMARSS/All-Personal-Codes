#include <stdio.h>

int main()
{int a,b,c;
    printf("Enter the value of a,b,c\n");
    scanf("%d,%d,%d",&a,&b,&c);
    a>b?a>c:b>c;
    c>a?c>b:a>b;
    printf("Greater number is:%d");
if (a=b=c)
{
    printf("All are equal");
}
else

    return 0;
}