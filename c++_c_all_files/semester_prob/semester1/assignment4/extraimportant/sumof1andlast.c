#include <stdio.h>
int main()
{
      int n,r,sum;
      printf("Enter the number");
      scanf("%d",&n);
      r=n%10;
      while (n/10!=0)
      {
            n=n/10;
      }
      sum=r+n;
      printf("The sum is %d",sum);
      return 0;  
}