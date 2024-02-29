#include <stdio.h>
int fiboo();//declaring the user defined function
int main()
{
    int n,i;//assigning the variable
    printf("Enter the number upto which you want fibo series:");
    scanf("%d",&n);//taking input for number of variables you want to print in fiboo series
    fiboo(n);//calling the user defined function
    printf("The fiboo series is :\n");
    for ( i = 0; i <n; i++)
    {
        printf("%d\n",fiboo(i));//printing the result for every function called
    }
    return 0;
}
int fiboo(int n)//defining the user defined function
{
    if (n==0)//terminating the user defined function
    {
        return 0;
    }
    else if (n==1)//terminating the user defined function
    {
        return 1;
    }
    else//again calling the function 
    {
        return fiboo(n-1)+fiboo(n-2);//breaking the function like tree
    }
}