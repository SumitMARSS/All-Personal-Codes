#include <stdio.h>

int main()
{
	int n;
	printf("Enter the number of row and column:\n");
	scanf("%d",&n);
	int a[n][n],b[n][n],c[n][n];
	printf("Enter 1st matrix:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Enter element %d,%d is...",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter 2st matrix:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Enter element %d,%d is...",i,j);
			scanf("%d",&b[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[i][j]=0;
			for (int k = 0; k < n; k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}	
		}
	}
	printf("Result of matrix multiplication:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Element %d,%d is %d\n",i,j,c[i][j]);
		}
	}
}