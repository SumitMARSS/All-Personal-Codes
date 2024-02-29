#include<stdio.h>
#include<stdlib.h>
#define MAX 25
struct node *queue[MAX];
int front=-1,rear=-1,top=-1;
struct node *stack[MAX];

struct node
{
    int info;
    struct node *left,*right;
};

void push(struct node *item)
{
        if(top==(MAX-1))
        {
            printf("Stack Overflow..\n");
        }
        top=top+1;
        stack[top]=item;
}

struct node *pop()
{
        struct node *item;
        if(top==-1)
        {
            printf("Stack Underflow....\n");
        }
        item=stack[top];
        top=top-1;
        return item;
}

int empty()
{
        if(top==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }           
}

struct node *createbst(struct node *root, int item)
{
    struct node *parent;
    struct node *node1;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->info=item;
    newnode->left=NULL;
    newnode->right=NULL;
    if (root==NULL)
    {
        root=newnode;
        root->left=NULL;
        root->right=NULL;
    }
    else
    {
        parent=NULL;
        node1=root;
        while (node1!=NULL)
        {
            parent=node1;
            if (item<node1->info)  
            {
                node1=node1->left;
            }
            else
            {
                node1=node1->right;
            }
        }
        if (item<parent->info)
        {
            parent->left=newnode;
        }
        else
        {
            parent->right=newnode;
        }
    }
    return root;
}

struct node *preorder(struct node *root)
{
    int i=1;
        struct node *ptr = root;
        push(ptr);
        while( !empty() )
        {
                ptr = pop();
                printf("Element %d is %d\n",i,ptr->info);
                i++;
                if(ptr->right!=NULL)
                {
                    push(ptr->right);
                }
                if(ptr->left!=NULL)
                {
                    push(ptr->left);
                }        
        }
        printf("\n");
        return root;
}

struct node *inorder(struct node *root)
{
    int i=1;
        struct node *ptr=root;
        while(1)
        {
            while(ptr->left!=NULL )
                {
                    push(ptr);
                    ptr = ptr->left;
                }
            while( ptr->right==NULL )
                {
                    printf("Element %d is :%d\n",i,ptr->info);
                    i++;
                    if(empty())
                    {
                        exit;
                    }
                    ptr = pop();
                }
            printf("Element %d is :%d\n",i,ptr->info);
            i++;
            ptr = ptr->right;
        }
        printf("\n");
        return root;
}

struct node *postorder(struct node *root)
{
    int i=1;
        struct node *ptr = root;
        struct node *q;
        q = root;
        while(1)
        {
                while(ptr->left!=NULL)
                {
                        push(ptr);
                        ptr=ptr->left;
                }

                while( ptr->right==NULL || ptr->right==q )
                {
                    printf("Element %d is :%d\n",i,ptr->info);
                    i++;
                    q = ptr;
                    if( empty() )
                    {
                        exit;
                    }  
                    ptr = pop();
                }
                push(ptr);
                ptr = ptr->right;
        }
        printf("\n");
        return root;
}

int main( )
{
    int x,item,i=1;
    struct node *root=NULL;
    do
    {
        printf("\n1. Create a binary search tree.\n");
        printf("2. In-order Traversal.\n");
        printf("3. Pre-order Traversal.\n");
        printf("4. Post-order Traversal.\n");
        printf("5. Exit from the program.\n");
        printf("Enter your option.\n");
        scanf("%d",&x);
        switch (x)
        {
        case 1:
            printf("Enter -1 to terminate:\n");
            printf("Enter the data item %d:\n",i);
            scanf("%d",&item);
            i++;
            while (item!=-1)
            {
                root=createbst(root,item);
                printf("Enter the data item %d:\n",i);
                scanf("%d",&item);
                i++;
            }
            printf("\nBinary Tree is CREATED....\n");
            break;
                case 2:
                    if(root==NULL)
                    {
                        printf("\nInorder-Traversal: Binary Tree is EMPTY...\n");
                    }
            	    else
                    {
                        root=inorder(root);
                    }
                    break;
                case 3:
                    if(root==NULL)
                    {
                        printf("\nPre-order-Traversal: Binary Tree is EMPTY...\n");
                    }
                    else
                    {
                        root=preorder(root);
                    }
                    break;
                case 4:
                    if(root==NULL)
                    {
                        printf("\nPre-order-Traversal: Binary Tree is EMPTY...\n");
                    }   
                    else
                    {
                        root=postorder(root);
                    }    
                    break;
                default:
                    printf("Program is Terminated/Ended\nAs you entered wrong input...\n");
                    break;
                }
        }while(x<=4);

        return 0;

}