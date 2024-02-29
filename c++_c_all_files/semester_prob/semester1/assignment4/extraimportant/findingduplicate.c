#include <stdio.h>
int main()
{
      int n,i,flag;
      printf("Enter the number you want to store in array");
      scanf("%d",&n);
      int a[n],k;
      for ( i = 1; i <=n; i++)
      {
            printf("Element %d is:",i);
            scanf("%d",&a[i]);
      }
      k=a[1];
      for ( i = 1; i <=n; i++)
      {
           if (k==a[i])
           {
                 //printf("%d is duplicate\n",k);
                 flag=1;
           }
           else
            {
                  //printf("No duplicate number is found\n");
            }
      }
      
      if (flag==1)
      {
            printf("Total number of duplicate elements found in the array is : %d",k);
      }
      else
      {
            printf("No duplicate element is found");
      }
      return 0;  
}
//solve for if you have entered more than 2 duplicate numbers like 44226