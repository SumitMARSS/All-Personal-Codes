#include<stdio.h>
int main()
{
    int n,i,j;//assigning variable
    printf("Enter the number of row you want to print pattern:\n");
    scanf("%d",&n);//taking input for rows you want
    for ( i =n-1; i>=0 ; i--)//logics that you want number of rows
        {
             for ( j = 0; j<=i; j++)//for number of column
             {
                 printf("*");//for printing output
             }
             printf("\n");//for new line
        }
    return  0;
}