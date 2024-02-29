#include <stdio.h>
int main()
{
    int n,i,j,k;//assigning variable
    printf("Input number of rows:");
    scanf("%d",&n);//taking input for rows you want
    for ( i = n; i >=1; i--)//number of rows
    {
        for ( k = 1; k <=i; k++)//for column,print *
        {
            printf("*");//for printing star
        }
        for ( j = n-1; j>=i; j--)//for spaces
        {
            printf("  ");//for printing spaces
        }
        for ( k = 1; k <=i; k++)//for column,print *
        {
            printf("*");//for printing star
        }
        
        printf("\n");//new rows
    }
    return 0;
}