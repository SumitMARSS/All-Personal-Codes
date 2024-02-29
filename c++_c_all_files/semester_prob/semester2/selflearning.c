#include <stdio.h>
#include <stdlib.h>
//we are using typedef because we don't want to use struct node,struct node again and again
typedef struct node
{
    int data;
    struct node *link;
}node;
//now we can directly define by name node
node *createlink();
void displaylink(node *head);
int main()
{
    int n,choice;
    node *HEAD=NULL;
    while (1)
    {
        printf("Enter 1 to craete\n");
        printf("Enter 2 to display\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                HEAD=createlink();
            break;
            case 2:
                displaylink(HEAD);
            break;
        default:
            printf("INVALID INPUT\n");
            exit(1);
            break;
        }
    }
}
node *createlink()
{
    int i,n;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    node *head=NULL;
    node *temp=NULL;
    node *ptr=NULL;
    for ( i = 1; i <=n; i++)
    {
        //lets create an indivisual node
        temp=(node *)malloc(sizeof(node));
        printf("Enter the data of %d element\n",i);
        scanf("%d",&temp->data);
        temp->link=NULL;
        if (head==NULL)///list is still empty
        {
            head=temp;//making temp as first node
        }
        else
        {
            ptr=head;
            while (ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            ptr->link=temp;
        }
    }
    return head;
}
void displaylink(node *head)
{
    int i=1;
    node *ptr=head;
    while (ptr!=NULL)
    {
        printf("Element %d is %d element\n",i,ptr->data);
        ptr=ptr->link;
        i++;
    }
    
}