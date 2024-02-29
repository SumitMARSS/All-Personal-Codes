#include <stdio.h>
#include <stdlib.h>

struct node
{
    int element;//queue element
    struct node *link;//a pointer pointing the node of its own type
};

    struct node *front=NULL;
    struct node *rear=NULL;
void linkqinsert()
{
    int value,x;
    do
    {
        printf("Enter the value you want to store in queue.\n");
        scanf("%d",&value);//taking input for value storing in queue
        struct node *newnode = (struct node *)malloc(sizeof(struct node));//creating a new node
        newnode->element=value;//giving newnode value
        newnode->link=NULL;//terminating newnode
        if (front==NULL && rear==NULL)
        {
            front=rear=newnode;//first connection
        }
        else
        {
            rear->link=newnode;//storing address of newnode in rear
            rear=newnode;//changing the address value of rear
        }
        printf("Enter 1 if you want to continue.\n");
        printf("Enter any other number if you don't want to give input.\n");
        scanf("%d",&x);//taking input to continue the queue
    } while (x==1);
}
void linkqdisplay()
{
    int i=1;//just to show no of element in queue
    struct node *ptr;//defining a pointer to move in each node
    if (front==NULL && rear==NULL)
    {
        printf("Queue is empty\nUnderflow\n");//underflow case
    }
    else
    {
        ptr=front;//giving first address
        while (ptr!=NULL)
        {
            printf("Element %d is %d\n",i,ptr->element);//printing data
            ptr=ptr->link;//moving forward by giving next address
            i++;//increasing element number
        }
    }  
}
void linkqdelete()
{
    struct node *ptr;//taking a new pointer
    ptr=front;//giving pointer first address to hold and at last we can release the garbage memory
    if (front==NULL && rear==NULL)
    {
        printf("Queue is empty.\nUnderflow\n");
    }
    else
    {
        front=front->link;//deleting
        free(ptr);//freeing the garbage memory
        printf("Your ELEMENT from queue is DELETED as per your request.\n");
        printf("Go and check in DISPLAY by entering 3.\n");
    }  
}
int main()
{
    int choice;
    do
    {
        printf("\nEnter 1 to insert an element to the queue.\n");
        printf("Enter 2 to delete an element from start to the queue.\n");
        printf("Enter 3 to display all elements to the queue.\n");
        printf("Enter 4 to exit.\n");
        printf("Enter your choice.\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            linkqinsert();
            break;
        case 2:
            linkqdelete();
            break;
        case 3:
            linkqdisplay();
            break;
        default:
            printf("You have entered a wrong input.\nAs program is terminated........\n");
            return 0;
            break;
        }
    } while (choice<=3);
}
