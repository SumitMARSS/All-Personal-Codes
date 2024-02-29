#include <stdio.h>
int main()
{
      int n,i,j,k=1,sum=0;
      printf("Input the number you want thr sum:");
      scanf("%d",&n);
      printf("The number you want is :");
      for ( i = 1; i <=n; i++)
      {
            k=1;
            for ( j = 1; j <=i; j++)
            {
                  k=k*i;     
            }
            printf("%d\t",k);
            sum=sum+k;
      }
      printf("Sum of the number is %d",sum);
      return 0;  
}