#include <stdio.h>
int main()
{int a,i,b,s=1,d;//defining the variables
printf("Enter the value of a\n");
scanf("%d",&a);//taking input
//logics 
for ( i = 1; i <=s ; )
{
    i=10;
    s=s*i;
    d=(7*(s-1))/9;//logic for repeating 7
    if (a <= s)//case to define when to take input
       { 
            b=d-a;
            printf("The complement of %d is %d-%d=%d\n",a,d,a,b);//printing the result
            break;
       }   
}
return 0;
}