#include <stdio.h>
int binarysearch();
int main()
{
    int n,k,i,j,x,pn;//defining variables
    printf("Enter the number you want to store in array:");
    scanf("%d",&n);//taking input for storing number in array 
    int a[n];//intialising array
    for (int i = 0; i <n; i++)
    {
        printf("Element %d:",i);
        scanf("%d",&a[i]);//taking input in array
    }
    printf("The numbers are ascending order:\n");//printing message
    for (int i = 0; i <n; i++)//same array location
    {
        for (int j = i+1; j <n; j++)//taking number from next array element
        {
            if (a[i]>a[j])//condition for swaping
            {
                a[i]=a[i]^a[j]^(a[j]=a[i]);//swaping
            }  
        }
    printf("%d\n",a[i]);//printing result
    }
    printf("Enter the number you want to search in array:");
    scanf("%d",&x);//input for searching the number
    k=n/2;//finding middle term
    pn=binarysearch(a,n,x,k);//calling the function
    return 0;//end
}
int binarysearch(int a[], int n,int x,int k)//declaring the function
{
    if (x==a[k])//when we gets the number
    {
        printf("Found ");//printing output
    }
    else if (x>a[k])//if search number is greater than mid array
    {
        k=n+k/2;//changing the value of k
        return binarysearch(a,n,x,k);//again calling
    }
    else if (x<a[k])//if search number is less than mid array
    {
        k=k/2;//changing the value of k
        return binarysearch(a,n,x,k);//again calling
    }
    else if (x!=a[k])
    {
        printf("Not found");//when not found
    }
}