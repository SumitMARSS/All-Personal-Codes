#include <stdio.h>
#include <string.h>
struct student//defining structure
{
    char name[600];//string  use for name
    int marks1;//marks of sub 1
    int marks2;//marks of sub 2
    int roll;//roll for students
};
void main()
{
    int n,k;//defining integer value
    printf("Enter the number of student");
    scanf("%d",&n);//taking input for number of students
    struct student s[n];//structure defing number of students
    float sum1=0,sum2=0,p,q,median1,median2,mode1,mode2;//defining real values
    k=n/2;//midd point
    for (int i = 1; i <=n; i++)//taking input for number of students taken
    {
        printf("\nEnter the name of %d student:",i);
        scanf("%s",&s[i].name);//taking input name
        printf("\nEnter the roll of %d student:",i);
        scanf("%d",&s[i].roll);//taking input roll
        printf("\nEnter the marks of %d student of Maths:",i);
        scanf("%d",&s[i].marks1);//taking input marks of Maths
        printf("\nEnter the marks of %d student of Computer:",i);
        scanf("%d",&s[i].marks2);//taking input marks of computer
    }
    printf("All you entered are:\n");//table formation
    printf("Roll\t Name\t   Maths\t    Computer\n");//printing heading
    for (int i = 1; i <=n; i++)
    {
        printf("%d\t %s   \t%d    \t%d \n",s[i].roll,s[i].name,s[i].marks1,s[i].marks2);//printing input given
    }
    for (int i = 1; i <=n; i++)
    {
        sum1=sum1+s[i].marks1;
        sum2=sum2+s[i].marks2;
    }
    p=sum1/n;//finding mean
    printf("The mean of marks for Maths is :%f\n",p);//printing mean of Maths
    q=sum2/n;//finding mean
    printf("The mean of marks for Computer is :%f\n",q);//printing mean of computer
    printf("The marks in Maths is ascending order:\n");//printing message for marks in ascending
    for (int i = 1; i <=n; i++)//same array of marks
    {
        for (int j = i+1; j <=n; j++)//taking number from next array element
        {
            if (s[i].marks1>s[j].marks1)//condition for swaping
            {
                s[i].marks1=s[i].marks1^s[j].marks1^(s[j].marks1=s[i].marks1);//swaping
            }   
        }
    printf("%d\t",s[i].marks1);//printing result
    }
    printf("\nThe marks in computer is ascending order:\n");//printing message for marks in ascending
    for (int i = 1; i <=n; i++)//same array of marks
    {
        for (int j = i+1; j <=n; j++)//taking number from next array element
        {
            if (s[i].marks2>s[j].marks2)//condition for swaping
            {
                s[i].marks2=s[i].marks2^s[j].marks2^(s[j].marks2=s[i].marks2);//swaping
            }    
        }
    printf("%d\t",s[i].marks2);//printing result
    }
    printf("\n");
    if (n%2==0)//when there are two medians
    {
        printf("\nThe median of marks of Maths is: %d and %d\n",s[k].marks1,s[k+1].marks1);//printing two medians
        printf("The median of marks of Computer is: %d and %d\n",s[k].marks2,s[k+1].marks2);//printing two medians
        median1=s[k].marks1+s[k+1].marks1/2;//making 1 median
        median2=s[k].marks2+s[k+1].marks2/2;//making 1 median
    }
    else if (n%2!=0)//when there is one medians
    {
        printf("The median of marks of Maths is: %d \n",s[k+1].marks1);//printing one medians
        printf("The median of marks of Computer is: %d\n ",s[k+1].marks2);//printing one medians
        median1=s[k+1].marks1;
        median2=s[k+1].marks2;
    }
    mode1=3*median1-2*p;//using formula
    mode2=3*median2-2*q;//using formula
    printf("The mode of marks of Maths is: %f \n",mode1);//printing mode
    printf("The mode of marks of Computer is: %f\n ",mode2);//printing mode
}