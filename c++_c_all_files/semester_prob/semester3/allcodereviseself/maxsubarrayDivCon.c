#include<stdio.h>
#include<math.h>

int  maxleft,maxright;
double rightsum = -INFINITY;
double leftsum = -INFINITY;

void display(int a[], int n)
{
    int i,sum=0;
    printf("Elements in array are:\n");
    for ( i = maxleft; i <= maxright; i++)    
    {
        printf("%d\t",a[i]);
        sum+=a[i];
    }
    printf("Total sum of subarray are : %d\n",sum);
}

int max_crossing_subarray(int a[] ,int low, int mid, int high)
{
    int sum=0,i,j,l,m,finalsum=0,k,tsum;
    for ( i = mid ; i >= low; i--)
    {
        sum+= a[i];
        if (sum>leftsum)
        {
            leftsum=sum;
            maxleft=i;
        }
    }
    sum= 0;
    for ( j = mid+1 ; j <= high; j++)
    {
        sum+=a[j];
        if (sum> rightsum)
        {
            rightsum=sum;
            maxright=j;
        }   
    } 
}

int find_max_subarray(int a[],int low,int high)
{
    int mid,leftlow,righthigh,cross;
    if (high ==low)
    {
        return (a,low,high);
    }
    else
    {
        mid=(low+high)/2;
    }
    leftlow= find_max_subarray(a,low,mid);
    righthigh =find_max_subarray(a,mid+1,high);
    cross=max_crossing_subarray(a,low,mid,high);
    if (leftsum>=rightsum && leftsum>=cross)
    {
        return leftlow;
    }
    else if (rightsum>=leftsum && rightsum>= cross)
    {
        return righthigh;
    }
    else
    {
        return cross;
    }
}

int main()
{
    int n,i,x,low=1,k,finalsum=0;
    printf("Enter the number of elements you want in array:\n");
    scanf("%d",&n);
    int a[n];
    for ( i = 1; i <= n; i++)
    {
        printf("Enter the %d element:\n",i);
        scanf("%d",&a[i]);
    }
    x=find_max_subarray(a,low,n);
    display(a,n);
}