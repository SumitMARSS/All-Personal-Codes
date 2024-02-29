#include<stdio.h>
#include <stdlib.h>

void merge(int a[100],int beg,int mid,int end)
{
	int i=beg,j=mid+1,index=beg,k,temp[100];
	while(i<=mid && j<=end)
	{
		if(a[i]<a[j])
		{
			temp[index]=a[i];
			i++;
			index++;
		}
		else
		{
		  temp[index]=a[j];
			j++;
			index++;	
		}
	}
	if(i>mid)
	{
		while(j<=end)
		{
			temp[index]=a[j];
			j++;
			index++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index]=a[i];
			i++;
			index++;
		}
	}
	for(k=beg;k<index;k++)
	a[k]=temp[k];
}

void merge_sort(int a[],int beg,int end)
{
	int mid;
	if(beg<end)
	{
	mid=(beg+end)/2;
	merge_sort(a,beg,mid);
	merge_sort(a,mid+1,end);	
	merge(a,beg,mid,end);
	}
}

int partition(int a[],int beg,int end)
{
	int left,right,temp,loc,flag;
	loc=beg;
	left=beg;
	right=end;
	flag=0;
	while(flag!=1)
	{
		while(a[loc]<=a[right] && (loc!=right))
		right--;
		if(loc==right)
		flag=1;
		else if(a[loc]>a[right])
		{
			temp=a[loc];
			a[loc]=a[right];
			a[right]=temp;
			loc=right;
		}
		if(flag!=1)
		{
			while(a[loc]>=a[left] &&(loc!=left))
			left++;
			if(loc==left)
			flag=1;
			else if(a[loc]<a[left])
			{
				temp=a[loc];
				a[loc]=a[left];
				a[left]=temp;
				loc=left;
			}
		}
	}
	return loc;
}

void quick_sort(int a[],int beg,int end)
{
	int loc;
	if(beg<end)
	{
		loc=partition(a,beg,end);
		quick_sort(a,beg,loc-1);
		quick_sort(a,loc+1,end);
	}
}

int main()
{
    int choice,n;
    printf("\nEnter no of elements in an array:\n");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Element %d:",i);
        scanf("%d",&arr[i]);
    }
    while (1)
    {
        printf("Enter 1 to quick sort array by merge sort:\n");
        printf("Enter 2 to sort array by merge sort:\n");
        printf("Enter any other number to exit...\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            int beg=0,end=n-1;
            merge_sort(arr,beg, end);
            printf("\nPrinting the elements after 'MERGE' sorting:\n");
	        for(int i=0;i<n;i++)
            {
                printf("Element arr[%d]:%d\n",i,arr[i]);
            }
            break;
        case 2:
            beg=0;
            end=n-1;
            quick_sort(arr,beg,end);
            printf("\nPrinting the elements after 'QUICK' sorting:\n");
            for(int i=0;i<n;i++)
            {
                printf("Element arr[%d]:%d\n",i,arr[i]);
            }
            break;
        default:
            printf("You entered wrong input.....\n....THANK YOU....\n");
            exit(0);
            break;
        }
    }
}