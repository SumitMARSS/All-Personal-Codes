#include <stdio.h>
int main()
{
    int n,i,j;//defining variables
    printf("Enter the number you want to store in array:");
    scanf("%d",&n);//taking input for storing number in array 
    int a[n];//intialising array
    for (int i = 1; i <=n; i++)
    {
        printf("Element %d:",i);
        scanf("%d",&a[i]);//taking input in array
    }
    printf("The numbers are ascending order:\n");//printing message
    for (int i = 1; i <=n; i++)//same array location
    {
        for (int j = i+1; j <=n; j++)//taking number from next array element
        {
            if (a[i]>a[j])//condition for swaping
            {
                a[i]=a[i]^a[j]^(a[j]=a[i]);//swaping
            }  
        }
    printf("%d\n",a[i]);//printing result
    }
    return 0;//end
}