#include<stdio.h>
int main()
{
    int n,i,j;//assigning variable
    printf("Enter the number of row you want to print pattern:");
    scanf("%d",&n);;//taking input for rows you want
    for ( i = 1; i <=n; i++)//logics that you want number of rows
    {
        for ( j = 1; j<=i ; j++)//for number of column
        {
            printf("*");//for printing output
        }
        printf("\n");//for new line
    }
    return  0;
}