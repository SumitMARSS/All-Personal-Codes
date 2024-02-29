#include <stdio.h>
int main()
{
    int n,i,j;//assigning variable
    printf("Enter the numbers of row:");
    scanf("%d",&n);//taking input for rows you want
    int a[n][j];//initialising the array variable
    printf("The series is :\n");
    for ( i = 0; i <=n; i++)//number of rows
    {
        for ( j = n; j >= i; j--)//for spaces
        {
            printf(" ");//managing space
        } 
        for ( j = 0; j <= i; j++)//for column,spaces and print result
        {
            if (j==0||i==j)//case for result 1
            {
               a[i][j]=1;
               printf("%d ",a[i][j]);//printing the result
            }
            else
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];//case for result other than one 
                printf("%d ",a[i][j]); //printing the result
            } 
        } 
        printf("\n");//for new line
    }
    return 0;
}