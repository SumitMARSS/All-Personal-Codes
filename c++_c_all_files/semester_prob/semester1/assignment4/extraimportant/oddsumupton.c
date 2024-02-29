#include <stdio.h>
int main()
{int i,n,sum=0;
printf("Enter numbers you want to enter");
scanf("%d",&n);
int a[n];
for ( i = 1; i <=n; i++)
{
    printf("Enter the %d number:",i);
    scanf("%d",&a[i]);
}
for ( i = 0; i <=n; i++)
{
    if (a[i]%2==1)
    {
        sum=sum+a[i];
    }
    else
    {
        continue;
    }
    
}
printf("The sum 0f odd numbers you entered are %d\n",sum);
return 0;
}