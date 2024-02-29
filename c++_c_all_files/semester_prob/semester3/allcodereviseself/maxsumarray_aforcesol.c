#include<stdio.h>
int main()
{
	int n,i,j,sum,maxsum,m,l;
	printf("Enter the number you want to store in array:\n");
	scanf("%d",&n);
	int a[n];
	for ( i = 1; i <= n; i++)
	{
		printf("Enter %d element:\n",i);
		scanf("%d",&a[i]);
	}
	maxsum=a[1];
	for ( i = 1; i <=n ; i++)
	{
		sum=0;
		for ( j = i; j <=n; j++)
		{
			sum+=a[j];
			if (sum > maxsum)
			{
				m=i;
				l=j;
				maxsum=sum;
			}
		}
	}
	printf("All elements which are in max subarray are:\n ");
	while (m<=l)
	{
		printf("%d\t",a[m]);
		m+=1;
	}
	printf("\nMax sum is %d\n",maxsum);
}