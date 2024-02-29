#include <stdio.h>
int main()
{
    int n;//assigning variable for you want to store in array
    printf("Enter the number you want to store in array\n");
    scanf("%d",&n);//taking input for numbers you want to show in array
    int a[n],i,flag=0,num,k=0;//assigning variable
    for ( i = 1; i <=n; i++)
        {
            printf("Element %d: ",i);
            scanf("%d",&a[i]);//taking input in array
        }
    printf("Enter the number you want to search in array");
    scanf("%d",&num);//taking input for numbers you want to search in array
    for ( i = 1; i <=n; i++)
        {
            if (a[i]==num)//searching number is stored in array or not
                {
                    flag=1;//output
                    k=k+1;//if number are repeated then added
                }
        }
    if (flag==1)//if found
        {
            printf("%d is found in array in %d location ",num,k);//if you found number in array
        }
    else
        {
            printf("%d is not found",num);//if you found number in array
        }
    return 0;
}