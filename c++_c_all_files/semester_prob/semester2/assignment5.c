#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coef;
    int exp;
    struct node *link;
};
struct node *start1=NULL;
struct node *start2=NULL;
struct node *start3=NULL;
struct node *createheadpol(struct node *);
struct node *displayheadpol(struct node *);
struct node *addheadpol(struct node *,struct node *,struct node *);

int main()
{
    int x;
    while (1)
    {
        printf("Enter 1 to create and display 1st polynomial:\n");
        printf("Enter 2 to create and display 2st polynomial:\n");
        printf("Enter 3 to create and display added of both polynomial:\n");
        printf("Enter any other number to exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&x);
        switch (x)
        {
            case 1:
                start1=createheadpol(start1);
                printf("The 1st polynomial is:\n");
                start1 = displayheadpol(start1);
            break;
            case 2:
                start2=createheadpol(start2);
                printf("The 2nd polynomial is:\n");
                start2 = displayheadpol(start2);
            break;
            case 3:
                printf("The addition of 1st and 2nd polynomial is:\n");
                start3 = displayheadpol(start3);
            break;
            default:
                printf("Wrong input\nYour program is terminated.\n");
                exit(0);
            break;
        }
    }  
}
struct node *createheadpol(struct node *start1)
{
    struct node *newnode, *ptr;
    int n,c;
    printf("Enter 0 to stop the numbe rof node:\n");
    printf("Enter the number/expo:\n");
    scanf("%d",&n);
    printf("Enter the coefficient:\n");
    scanf("%d",&c);
    while (n!=0)
    {
        if (start1==NULL)
        {
           newnode=(struct node *)malloc(sizeof(struct node));
           newnode->coef=c;
           newnode->exp=n;
           newnode->link=NULL;
           start1=newnode;
        }
        else
        {
            ptr=start1;
            while (ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            newnode=(struct node *)malloc(sizeof(struct node));
            newnode->coef=c;
            newnode->exp=n;
            newnode->link=NULL;
            ptr->link=newnode;
        }
        printf("\nEnter the number/expo:\n");
        scanf("%d",&n);
        if (n==0)
        {
            break;
        }
        printf("Enter the coefficient:");
        scanf("%d",&c);
    }
    return start1;
}

struct node *displayheadpol(struct node *start1)
{
    struct node *ptr;
    ptr=start1;
    while (ptr!=NULL)
    {
        printf("( %d x^%d )+",ptr->coef,ptr->exp);
        ptr=ptr->link;
    }
    printf("\n");
    return start1;
}

struct node *addnode(struct node *start, int c, int n)
{
struct node *ptr, *newp;
if(start == NULL)
{
newp = (struct node *)malloc(sizeof(struct node));
newp -> coef = c;
newp -> exp = n;
newp -> link = NULL;
start = newp;
}
else
{
ptr = start;
while(ptr -> link != NULL)
ptr = ptr -> link;
newp = (struct node *)malloc(sizeof(struct node));
newp -> coef = c;
newp -> exp = n;
newp -> link = NULL;
ptr -> link = newp;
} start;
}


struct node *addheadpol(struct node *start1, struct node *start2, struct node *start3)
{
struct node *ptr1, *ptr2;
int sumcoff;
start3 = addnode(start3, 0, -1);//Header Node
ptr1 = start1->link,
ptr2 = start2->link;
while(ptr1!= NULL && ptr2!= NULL)
{
if(ptr1->exp==ptr2->exp)
{
sumcoff = ptr1->coef + ptr2->coef;
start3 = addnode(start3, sumcoff, ptr1->exp);
ptr1 = ptr1->link;
ptr2 = ptr2->link;
}}}