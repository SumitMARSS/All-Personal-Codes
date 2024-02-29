#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prv;
    int inform;
    struct node *next;
};

struct node *start = NULL;

struct node *createcdll(struct node *);
struct node *printcdll(struct node *);
struct node *inscdllfirst(struct node *);
struct node *inscdllend(struct node *);
struct node *inscdllafgn(struct node *);
struct node *delcdllfirst(struct node *);
struct node *delcdllend(struct node *);

int main()
{
    int choice;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    while (1)
    {
        printf("\nEnter 1 if you want to create link list\n");
        printf("Enter 2 if you want to display link list\n");
        printf("Enter 3 if you want to insert a node at the beginning of circular doubly link list\n");
        printf("Enter 4 if you want to insert a node at the end of circular doubly link list\n");
        printf("Enter 5 if you want to insert a node after the node of circular doubly link list\n");
        printf("Enter 6 if you want to delete a node from the beginning of circular doubly linked list:\n");
        printf("Enter 7 if you want to delete a node from the end of circular doubly linked list:\n");
        printf("Enter 8 if you want to exit:\n");
        printf("Enter your choice\n");//taking input
        scanf("%d", &choice);
        //using switch case for menu derive
        switch (choice)
        {
        case 1:
            createcdll(ptr);
            break;
        case 2:
            printcdll(ptr);
            break;
        case 3:
            inscdllfirst(ptr);
            break;
        case 4:
            inscdllend(ptr);
            break;
        case 5:
            inscdllafgn(ptr);
            break;
        case 6:
            delcdllfirst(ptr);
            break;
        case 7:
            delcdllend(ptr);
            break;
        case 8:
            printf("\nSORRY YOU ENTERED WRONG CHOICE\nYOU GET EXIT......\n");
            exit(0);
            break;
        }
    }
}
//user defined function to create circularly doubly linked list
struct node *createcdll(struct node *a)
{
    int n;
    printf("Enter no of nodes you want:\n");
    scanf("%d", &n);
    if (n != 0)
    {
        int data;
        struct node *newnode, *extra;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data:\n");
        scanf("%d", &data);
        newnode->inform = data;
        start = newnode;
        extra = start;
        newnode->next = extra;
        newnode->prv = start;
        for (int i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &data);
            newnode->inform = data;
            newnode->prv = extra;
            newnode->next = start;
            extra->next = newnode;
            extra = extra->next;
        }
    }
    return start;
}
//user defined function to display the input data
struct node *printcdll(struct node *a)
{
    struct node *extra;
    if (start == NULL)
    {
        printf("Under Flow\n");
    }

    extra = start;
    printf("The data you entered are:\n");
    while (extra->next != start)
    {
        printf("%d\n", extra->inform);
        extra = extra->next;
    }
    printf("%d\n", extra->inform);
    return start;
}
//user define function to insert data at first
struct node *inscdllfirst(struct node *a)
{
    int data;
    struct node *newnode, *extra;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Over Flow\n");
    }
    else
    {
        printf("Enter data you want to insert at the beginning\n");
        scanf("%d", &data);
        newnode->inform = data;
        if (start == NULL)
        {
            start = newnode;
            newnode->next = start;
            newnode->prv = start;
        }
        else
        {
            extra = start;
            while (extra->next != start)
            {
                extra = extra->next;
            }
            extra->next = newnode;
            newnode->prv = extra;
            start->prv = newnode;
            newnode->next = start;
            start = newnode;
            printf("\nGiven node is added at the beginning\n");
            printf("If you want to check you can check by using option 2\n");
        }
    }
    return start;
}
//user define function to insert data at end
struct node *inscdllend(struct node *a)
{
    int data;
    struct node *newnode, *extra;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Over Flow\n");
    }
    else
    {
        printf("Enter data you want to insert at the end\n");
        scanf("%d", &data);
        newnode->inform = data;
        if (start == NULL)
        {
            start = newnode;
            newnode->next = start;
            newnode->prv = start;
        }
        else
        {
            extra = start;
            while (extra->next != start)
            {
                extra = extra->next;
            }
            extra->next = newnode;
            newnode->prv = extra;
            start->prv = newnode;
            newnode->next = start;
            printf("\nGiven node is added at the end.\n");
            printf("If you want to check you can check by using option 2\n");
        }
    }
    return start;
}
//user define function to insert data at your desire place
struct node *inscdllafgn(struct node *a)
{
    int data;
    struct node *newnode, *extra;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Over Flow\n");
    }
    else
    {
        printf("Enter data you want to insert:\n");
        scanf("%d", &data);
        newnode->inform = data;
        if (start == NULL)
        {
            start = newnode;
            newnode->next = start;
            newnode->prv = start;
        }
        else
        {
            int value;
            printf("Enter value of node after which a node to be inserted:\n");
            scanf("%d", &value);
            extra = start;
            while (extra->inform != value)
            {
                extra = extra->next;
            }
            newnode->next = extra->next;
            extra->next->prv = newnode;
            extra->next = newnode;
            newnode->prv = extra;
            printf("\nGiven node is added by given information\n");
            printf("If you want to check you can check by using option 2\n");
        }
    }
    return start;
}
//user define function to delete data from first
struct node *delcdllfirst(struct node *a)
{
    struct node *extra;
    if (start == NULL)
    {
        printf("Under Flow\n");
    }
    else
    {
        extra = start;
        while (extra->next != start)
        {
            extra = extra->next;
        }
        extra->next = start->next;
        start->next->prv = extra;
        free(start);
        start = extra->next;
        printf("\nThe first node is deleted\n");
        printf("If you want to check you can check by using option 2\n");
    }
    return start;
}
//user define function to delete data from end
struct node *delcdllend(struct node *a)
{
    struct node *extra;
    if(start == NULL)
    {
        printf("Over Flow:\n");
    }
    else
    {
        extra = start;   
        while(extra->next != start)  
        {  
            extra =extra -> next;   
        }  
        extra -> prv -> next = start;  
        start -> prv = extra -> prv;    
        free(extra);  
        printf("\nThe last node is deleted\n");  
        printf("If you want to check you can check by using option 2\n");
    }
    return start;
}