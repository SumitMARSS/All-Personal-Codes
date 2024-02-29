#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * top = NULL;

void display()
{
    if (top==NULL)
    {
        printf("Underflow\nYour stack is empty...\n");
    }
    else
    {
        int i=1;
        struct node *ptr;
        ptr=top;
        while (ptr!=NULL)
        {
            printf("Element %d is %d...\n",i,ptr->data);
            ptr=ptr->next;
            i++;
        } 
        printf("\n");
    }
    
    
}

void push(int x)
{
    struct node *newnode=(struct node *)malloc(sizeof (struct node));
    newnode->data=x;
    if (top==NULL)
    {
        newnode->next=NULL;
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    } 
    printf("\nYour item is pushed into stack...\n");
}

void pop()
{
    struct node * ptr;
    if (top==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        ptr=top;
        top=top->next;
        free(ptr);
        printf("\nYour item is poped from stack...\n");
    } 
}

int main()
{
    int choice,x;
    while (1)
    {
        printf("Enter 1 to push:\n");
        printf("Enter 2 to pop: \n");
        printf("Enter 3 to display:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to push in stack:...\n");
            scanf("%d",&x);
            push(x);
            printf("\n");
            break;
        case 2:
            pop();
            printf("\n");
            break;
        case 3:
            display();
            printf("\n");
            break;
        
        default:
            printf("INVALID INPUT\nSORRY....");
            exit(0);  
        }
    }  
    return 0;
}