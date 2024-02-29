#include <stdio.h>
int main()
{
    int n;//assigning variable
    printf("Enter the number you want to store in array\n");
    scanf("%d",&n);//taking input for numbers you want to show in array
    int a[n],i,sum=0;
    float x;//assigning real variable
    for ( i = 1; i <=n ; i++)
        {
            printf("Element %d is : ",i);
            scanf("%d",&a[i]);//taking input in array
        }
    for ( i = 1; i <=n; i++)
        {
            sum=sum+a[i];//sum of all the elements you have entered
        }
    x=(float)sum/n;//finding the mean value 
    printf("The mean of all the elements in array are %f",x);//printing the result
    return 0;
}