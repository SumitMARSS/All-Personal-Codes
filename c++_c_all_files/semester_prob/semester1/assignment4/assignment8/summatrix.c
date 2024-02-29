#include <stdio.h>
int main()
{
    int r,c,i,j,m,n;//assigning variable
    printf("Enter the number of rows for first matrix:");
    scanf("%d",&r);
    printf("Enter the number of column for first matrix:");
    scanf("%d",&c);
    printf("Enter the number of rows for second matrix:");
    scanf("%d",&m);
    printf("Enter the number of column for second matrix:");
    scanf("%d",&n);
    if (m!=r || c!=n)//condition when no addition is possible
    {
        printf("INVALID INPUT");
        return 0;
    }
    int a[r][c],b[m][n],p[r][c];//assigning variable for you want to store in array matrix
    printf("Enter the first matrix:\n");
    for ( i = 1; i <=r; i++)//rows we get in first matrix
    {
        for ( j = 1; j <=c; j++)//column we get in first matrix
        {
            printf("Element %d,%d\t",i,j);
            scanf("%d",&a[i][j]);//taking input in array matrix
        } 
    }
    printf("Enter the second matrix:\n");
    for ( i = 1; i <=m; i++)//rows we get in second matrix
    {
        for ( j = 1; j <=n; j++)//column we get in second matrix
        {
            printf("Element %d,%d\t",i,j);
            scanf("%d",&b[i][j]);//taking input in array matrix
        } 
    }
    printf("The addition of two matrix is :\n");
    for ( i = 1; i <=r; i++)//rows we get in resultant matrix
    {
        for ( j = 1; j <=c; j++)//column we get in resultant matrix
        {
            p[i][j]=a[i][j]+b[i][j];//addition
            printf("The %d,%d element is %d\n",i,j,p[i][j]);//printing resultant array matrix
        } 
    }
    return 0;
}