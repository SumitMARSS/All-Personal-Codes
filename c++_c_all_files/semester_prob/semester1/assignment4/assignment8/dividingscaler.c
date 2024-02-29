#include <stdio.h>
int main()
{
    int r,c,i,j,x;//assigning variable
    printf("Enter the number of rows:");
    scanf("%d",&r);
    printf("Enter the number of column:");
    scanf("%d",&c);//getting input for number of rows, column
    printf("Enter the number you want to divide:");
    scanf("%d",&x);//getting input the scalar you want to divide
    int a[r][c];
    float b[r][c];//assigning variable for you want to store in array matrix
    printf("Enter the first matrix:\n");
    for ( i = 1; i <=r; i++)//rows we get in first matrix
    {
        for ( j = 1; j <=c; j++)//column we get in first matrix
        {
            printf("Element %d,%d\t",i,j);
            scanf("%d",&a[i][j]);//taking input in array matrix
        } 
    }
    for ( i = 1; i <=r; i++)//rows we get in resultant matrix
    {
        for ( j = 1; j <=c; j++)//column we get in resultant matrix
        {
            b[i][j]=(float)a[i][j]/x;//dividing
            printf("Element %d,%d is :%f\n",i,j,b[i][j]);//printing resultant array matrix
        } 
    }
    return 0;
}