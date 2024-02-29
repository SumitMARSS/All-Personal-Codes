#include <stdio.h>
int main()
{
    int n,i,j,k=0;//assigning variable
    printf("Input number of rows:");
    scanf("%d",&n);//taking input for rows you want
    printf("1\n");//printing first 1
    for ( i = 1; i <n; i++)//logics for number of rows you want
    {
        printf("1");//printing 1 at first of column
        for ( j = 1; j <=i; j++)//logics for number of column you want
        {
            k=k*j;//logics for 0
            printf("%d",k);//printing 0 while making pattern
        }
        printf("1");//printing 1 at last of column
        printf("\n");//introducing new row
    } 
    return 0;
}