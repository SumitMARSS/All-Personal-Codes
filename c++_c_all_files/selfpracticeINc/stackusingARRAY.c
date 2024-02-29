#include <stdio.h>
#include <stdlib.h>
#define MAX 7
int stack[MAX],Top= -1;

int push(int stack[],int item)
{
    if (Top==MAX-1)
    {
        printf("Overflow case\nStack is full\n");
        return Top;
    }
    Top=Top+1;
    stack[Top]=item;
    return Top; 
}

int pop(int stack[],int item)
{
    if (Top==-1)
    {
        printf("Underflow case\n Stack is empty\n");
        return Top;
    }
    item==stack[Top];
    if (item !=-1)
        {
            printf("The item is deleted having value %d\n",item);
        }
    Top=Top-1;
    return Top;
}

void display(int stack[])
{
    if (Top==-1)
    {
        printf("Stack is empty\n");
    }
    for (int i = Top; i >=0; i--)
    {
        printf("%d element is %d in stack\n",i,stack[i]);
    }
}

int main()
{
    int x,item;

    while (1)
    {
        printf("Enter 1 to push a stack\n");
        printf("Enter 2 to pop a stack\n");
        printf("Enter 3 to display a stack\n");
        printf("Enter your choice:\n");
        scanf("%d",&x);
        switch (x)
        {
        case 1:
            printf("Enter the number/iitem to be pushed in stack\n");
            scanf("%d",&item);
            push(stack,item);
            break;
        case 2:
            pop(stack,item);
            printf("Your item is poped from the stack array...\n");
            break;
        case 3:
            display(stack);
            break;
        default:
            printf("Wrong input\n");
            exit(0);
            break;
        }
    }
    
}