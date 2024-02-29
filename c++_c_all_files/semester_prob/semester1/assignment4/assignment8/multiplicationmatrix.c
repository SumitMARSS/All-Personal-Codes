#include <stdio.h>
int main()
{
    int r,c,i,j,m,n,sum=0,k;//assigning variable
    printf("Enter the number of rows for first matrix:");
    scanf("%d",&r);
    printf("Enter the number of column for second matrix:");
    scanf("%d",&c);
    printf("Enter the number of rows for second matrix:");
    scanf("%d",&m);
    printf("Enter the number of column for second matrix:");
    scanf("%d",&n);
    if (m!=c)//condition when no multiplication is possible
    {
        printf("INVALID INPUT FOR MULTIPLICATION");
        return 0;
    }
    int a[r][c],b[m][n],p[r][n];//assigning variable for you want to store in array matrix
    printf("Enter the first matrix:\n");
    for ( i = 0; i <r; i++)//rows we get in first matrix
    {
        for ( j = 0; j <c; j++)//column we get in first matrix
        {
            printf("Element %d,%d :",i,j);
            scanf("%d",&a[i][j]);//taking input in array matrix
        } 
    }
    printf("Enter the second matrix:\n");
    for ( i = 0; i <m; i++)//rows we get in second matrix
    {
        for ( j = 0; j <n; j++)//columns we get in second matrix
        {
            printf("Element %d,%d :",i,j);
            scanf("%d",&b[i][j]);//taking input in array matrix
        } 
    }
    printf("The multiplication of first and second matrix:\n");
    for ( i = 0; i <r; i++)//rows we get in resultant matrix
    {
        for ( j = 0; j <n; j++)//columns we get in resultant matrix
        {
            if (c==m)//matrix multiplication possible
            {
                
                for (int k = 0; k <=m-1; k++)//addition after multiplying the terms as per formula
                {
                    sum=sum+a[i][k]*b[k][j];//adding all the term
                }
            }
            p[i][j]=sum;
            printf("Element %d,%d is :%d\n",i,j,p[i][j]);//printing array matrix
            sum=0; //for making sum again 0 for next condition
        } 
    }
    printf("THANK YOU");
    return 0;
}