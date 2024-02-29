#include <stdio.h>
int main()
{
    int n,i,j,k;//assigning variable
    printf("Input number of rows:");
    scanf("%d",&n);//taking input for rows you want
    for ( i = 1; i <=n; i++)//number of rows
    {
        for ( j = n; j>=i; j--)//for spaces
        {
            printf(" ");//managing space
        }
        for ( k = 1; k <=i; k++)//for column,spaces and print *
        {
            printf("* ");//printing output
        }
        printf("\n");//for new rows
    }
    return 0;
}