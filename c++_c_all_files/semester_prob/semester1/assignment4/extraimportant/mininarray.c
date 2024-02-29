#include <stdio.h>
int main()
{
    int n,i,flag,min;
    printf("Enter the number you want to store in array");
    scanf("%d",&n);
    int a[n];
    for ( i = 1; i <=n; i++)
        {
            printf("Element %d is:",i);
            scanf("%d",&a[i]);
        }
    min=a[1];
    for ( i = 1; i <=n; i++)
    {
        if (min>a[i])
        {
            min=a[i];
        }
    }
    printf("The min number stored in array is %d",min);
    return 0;
}
    