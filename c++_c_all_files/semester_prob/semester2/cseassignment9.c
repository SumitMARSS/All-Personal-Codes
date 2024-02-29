#include <stdio.h>
#include <stdlib.h>

struct node
{
    int element;
    struct node *prv, *link;
};
struct node *front=NULL;
struct node *rear=NULL;

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->element=data;
    newnode->link = newnode->prv = NULL;
    return (newnode);
}

void node()
{
    front=createnode(0);
    rear=createnode(0);
    front->link=rear;
    rear->prv=front;
}
/* insertion at the front of the deque */
void insertleft()
{
    int data;
    printf("Enter the data you want to insert\n");
    scanf("%d",&data);
    struct node *newnode, *ptr;
    newnode=createnode(data);
    ptr=front->link;
    front->link=newnode;
    newnode->prv=front;
    newnode->link=ptr;
    ptr->prv=newnode;
    printf("\nYour element is INSERTED\n");
    printf("Go and Check in Display\n\n");
}
/*insertion at the rear of the deque */
void insertright()
{
    int data;
    printf("Enter the data you want to insert\n");
    scanf("%d",&data);
    struct node *newnode, *ptr;
    newnode=createnode(data);
    ptr=rear->prv;
    rear->prv=newnode;
    newnode->link=rear;
    newnode->prv=ptr;
    ptr->link=newnode;
    printf("\nYour element is INSERTED\n");
    printf("Go and Check in Display\n\n");

}
/* deletion at the front of the deque */
void deleteleft()
{
    struct node *ptr;
    if (front->link==rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        ptr = front->link;
        front->link= ptr->link;
        ptr->link->prv=front;
        free(ptr);
        printf("\nYour element is DELETED\n");
        printf("Go and Check in Display\n\n");
    }
}
/* deletion at the rear of the deque */
void deleteright()
{
    struct node *ptr;
    if (rear->prv== front)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        ptr = rear->prv;
        rear->prv=ptr->prv;
        ptr->prv->link=rear;
        free(ptr);
        printf("\nYour element is DELETED\n");
        printf("Go and Check in Display\n\n");
    }
}
/* display elements present in the deque */
void displaydeque()
{
    int i=1;
    struct node *ptr;
    if (front->link==rear)
    {
        printf("Queue is Empty\n");
        exit(0);
    }
    else
    {
        ptr=front->link;
        while (ptr!=rear)
        {
            printf("Element %d is %d\n",i,ptr->element);
            ptr=ptr->link;
            i++;
        }
    }
}

void outputdeque()
{
    int choice;
    do
    {
        printf("\nOUTPUT RESTRICTED DEQUE\n");
        printf("1. Insert at right\n");
        printf("2. Insert from left\n");
        printf("3. Delete from left\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your option:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insertright();
            break;
        case 2:
            insertleft();
            break;
        case 3:
            deleteleft();
            break;
        case 4:
            displaydeque();
            break;
        default:
            printf("Program is Terminated/Ended\nAs you entered wrong input...\n");
            break;
        }
    } while (choice<=4);
    
}

void inputdeque()
{
    int option;
    do
    {
        printf("\nINPUT RESTRICTED DEQUE\n");
        printf("1. Insert at right\n");
        printf("2. Delete from left\n");
        printf("3. Delete from right\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your option:\n");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            insertright();
            break;
        case 2:
            deleteleft();
            break;
        case 3:
            deleteright();
            break;
        case 4:
            displaydeque();
            break;
        default:
            printf("Program is Terminated/Ended\nAs you entered wrong input...\n");
            break;
        }
    } while (option<=4);
    
}
void main()
{
    int x;
    node();
    do
    {
        printf("\n1. Input restricted deque.\n");
        printf("2. Output restricted deque.\n");
        printf("Enter your option 1. and 2.\n");
        scanf("%d",&x);
        switch (x)
        {
        case 1:
            inputdeque();
            break;
        case 2:
            outputdeque();
            break;
        default:
            printf("Program is Terminated/Ended\nAs you entered wrong input...\n");
            
            break;
        }
    } while (x<=2);
}