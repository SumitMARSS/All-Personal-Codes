#include<stdio.h>
int main()
{
    int n,i,j,k,p=72;//assigning variable
    printf("Enter the number of row you want to print pattern:");
    scanf("%d",&k);;//taking input for rows you want
    n=k+2;
    for ( i = 1; i <n/2; i++)//logics for number of rows you want
    {
        for ( j = 1; j<=i ; j++)//for number of column
        {
            if (j==1)//for first column
            {
                printf("%c\t",p);//for printing output and condition for 'H'
            }
            else if (j==2)//for second column
            {
                p=p-3;//condition for 'E'
                printf("%c\t",p);//for printing output
                p=72;//giving again value of p=72
            }
            else if (j==3)//for third column
            {
                p=p+4;//condition for 'L'
                printf("%c\t",p);//for printing output
                p=72;//giving again value of p=72
            }
            else if (j==4)//for four column
            {
                p=p+4;//condition for 'L'
                printf("%c\t",p);//for printing output
                p=72;//giving again value of p=72
            }
            else if (j==5)//for fifth column
            {
                p=p+7;//condition for 'O'
                printf("%c\t",p);//for printing output
                p=72;//giving again value of p=72
            } 
        }
        printf("\n");//for new rows
    }
    for ( i = n/2; i >=0; i--)//logics for number of rows you want
    {
        for ( j = 1; j<=i ; j++)//for number of column
        {
           if (j==1)//for first column
            {
                printf("%c\t",p);//for printing output and condition for 'H'
            }
            else if (j==2)//for second column
            {
                p=p-3;//condition for 'E'
                printf("%c\t",p);//for printing output
                p=72;//giving again value of p=72
            }
            else if (j==3)//for third column
            {
                p=p+4;//condition for 'L'
                printf("%c\t",p);//for printing output
                p=72;//giving again value of p=72
            }
            else if (j==4)//for four column
            {
                p=p+4;//condition for 'L'
                printf("%c\t",p);//for printing output
                p=72;//giving again value of p=72
            }
            else if (j==5)//for fifth column
            {
                p=p+7;//condition for 'O'
                printf("%c\t",p);//for printing output
                p=72;//giving again value of p=72
            } 
        }
        printf("\n");//for new rows
    }
    return  0;
}