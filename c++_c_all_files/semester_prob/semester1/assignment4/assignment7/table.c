#include <stdio.h>
int main()
{
    int n,i,x;//assigning variable
    printf("Enter the number you want to print the table\n");
    scanf("%d",&n);//taking input for numbers you want the table
    printf("The table of %d is:\n",n);
    //logics for table
    for ( i = 1; i <=10; i++)
        {
            x=n*i;//table multiplication
            printf("%d*%d=%d\n",n,i,x);//for printing output
        }
    return 0;
}