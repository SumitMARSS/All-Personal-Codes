#include <stdio.h>

int main()
{int n,a=0,c,b=1,i;
    printf("Enter the number of terms n:");
    scanf("%d",&n);
    //for printing the value of n//
    printf("%d\n%d\n",a,b);
    //logics//
    for (i = 0; i <n-2; i++)
    {
        c=a+b;
        a=b;
        b=c;
        // for repeating the values//
        printf("%d\n",c);
    }
    return 0;
}