#include <stdio.h>
void read();//just to declare user function
void display();//just to declare user function
void insend();//just to declare user function
void inspos();//just to declare user function
void delend();//just to declare user function
void delpos();//just to declare user function
void mergearray();//just to declare user function
int main()
{
    int option,n,m;//defining integer value
    printf("Enter the number you want to store in array1:\n");
    scanf("%d",&n);//taking input of number stored in array1
    printf("Enter the number you want to store in array2:\n");
    scanf("%d",&m);//taking input of number stored in array2
    int a[n],b[m];//defining array
    while (1)//using infinite loop
    {
        printf("\n Enter 1  to read one dimensional array");
        printf("\n Enter 2 to display one dimensional array");
        printf("\n Enter 3 to insert a new element at the end of 1D array");//giving instruction
        printf("\n Enter 4 to insert a new element at any position of 1D array");
        printf("\n Enter 5 to delete element from the end of 1D array");
        printf("\n Enter 6 to delete element from any position of 1D array");
        printf("\n Enter 7 to merge the two 1D array");
        printf("\n Enter any other number to exit/end the program");
        printf("\nThe number is ....\n");
        scanf("%d",&option);//taking input for choice
        
    
    switch (option)//using switch function for combining problems
    {
        case 1:
            read(a,n);//just read the array1
            read(b,m);//just read the array2
            break;
        case 2:
            display(a,n);//display the array1
            display(b,m);//just display the array2
            break;
        case 3:
            int val;//defining integer value
            printf("Enter the new element you want to add at end of array1:");
            scanf("%d",&val);//taking input the number we want to add at end of array1
            insend(a,n,val);//using user defined function
            break;
        case 4:
            int val1,pos;//defining integer value
            printf("Enter the place you want to add new element in array1:");
            scanf("%d",&pos);//taking the place input
            printf("Enter the new element you want to add at %d place of array:",pos);
            scanf("%d",&val1);//taking input the number we want to add at given place of array1
            inspos(a,n,pos,val1);//using user defined function
            break;
        case 5:
            delend(a,n);//using user defined function
            break;
        case 6:
            int pos1;//defining integer value
            printf("Enter the place you want to delete in array1:");
            scanf("%d",&pos1);//taking input the position we want to delete
            delpos(a,n,pos1);//using user defined function
            break;
        case 7:
            mergearray(a,b,n,m);//using user defined function
            break;
        default:
            printf("INVALID INPUT");//for all other input
            return 0;
    }
    }
}
void read (int a[],int n)//defining the user defined function
{
    for (int i = 1; i <=n; i++)
    {
        printf("Element %d is:",i);
        scanf("%d",&a[i]);//taking input the array
    }  
}
void display (int a[],int n)//defining the user defined function
{
    for (int i = 1; i <=n; i++)
    {
        printf("Element %d is: %d\n",i,a[i]);//printing array
    }  
}
void insend (int a[], int n, int val)//defining the user defined function
{
    n=n+1;//increasing array size by 1
    a[n]=val;//giving last array value
    printf("The array is:\n");
    display(a,n);//display final array
}
void inspos(int a[], int n, int pos, int val1)//defining the user defined function
{
    n=n+1;//increasing array size by 1
    for (int i = n-1; i >=pos-1; i--)
    {
        a[i+1]=a[i];//shifting 
    }
    a[pos]=val1;//giving value
    display(a,n);//display final array
}
void delend(int a[],int n)//defining the user defined function
{
    a[n]=NULL;//giving the end value null
    n=n-1;//decresing the array size to 1
    display(a,n);//display final array
}
void delpos(int a[], int n, int pos1)//defining the user defined function
{
    for (int i = pos1; i <=n; i++)
    {
        a[i]=a[i+1];//shifting
    }
    n=n-1;//decresing the array size to 1
    display(a,n);//display final array
}
void mergearray(int a[],int b[],int n,int m)//defining the user defined function
{
    int c[100],i,j;
    for ( i = 1; i <=n; i++)
    {
        c[i]=a[i];//copying in first array
    }
    for (j = 1; j <=m; j++)
    {
        c[i]=b[j];//copying in second array
        i++;
    }
    n=n+m;//increasing the array size value
    display(c,n);//display final array
}