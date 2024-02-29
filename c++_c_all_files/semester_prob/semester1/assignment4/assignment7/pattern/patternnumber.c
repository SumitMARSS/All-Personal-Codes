#include<stdio.h>
int main()
{
    int n,i,j,k=0;//assigning variable
    printf("Enter the number of row you want to print pattern:");
    scanf("%d",&n);;//taking input for rows you want
    for ( i = 1; i <=n; i++)//logics for number of rows you want
    {
        for ( j = 1; j<=i ; j++)//for number of column
        {
            k=k+1;//proceeding number series
            printf("%d\t",k);//for printing output
        }
        printf("\n");//for new rows
    }
    return  0;
}