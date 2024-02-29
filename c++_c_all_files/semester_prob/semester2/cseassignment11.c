#include <stdio.h>
#include <stdlib.h>

struct node
{
        int info;
        unsigned int rthread:1;
        struct node *left , *right;
};

struct node *insertelement(struct node *root, int data)
{
    struct node *temp, *ptr, *new;
    int found=0;
    ptr=root;
    new=NULL;
    while (ptr!=NULL)
    {
        if (data==ptr->info)
        {
            found=1;
            break;
        }
        new=ptr;
        if (data > ptr->info)
        {
            if(ptr->rthread == 0)
            {
                ptr = ptr->right;
            }
            else
            {
                break;
            }                
        }
    }
    if (found)
    {
        printf("Repeated data is entered\nRepeated data can't be added\nPlease enter DIFFERENT Data.\n");
    }
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->info=data;
        temp->rthread=1;
        if (new==NULL)
        {
            root=temp;
            temp->left=NULL;
            temp->right=NULL;
        }
        else if( data > new->info )
        {
            temp->left=new;
            temp->right=new->right;
            new->rthread=0;
            new->right=temp;
        }
    }
    return root;
}

void inorderbst(struct node *root)
{
    int i=1;
    struct node *save, *par;
    save=root;
    if(root == NULL )
        {
            printf("Tree is empty\n");
            return;
        }
    do
    {
        par=NULL;
        while (save!=NULL)
        {
            par=save;
            save=save->left;
        }
        if (par!=NULL)
        {
            printf("Element %d is %d\n",i,par->info);
            i++;
            save=par->right;
            while (par->rthread=1 && save!=NULL)
            {
                printf("Element %d is %d\n",i,save->info);
                i++;
                par=save;
                save=save->right;
            }
        } 
    } while (save!=NULL);
}

int main()
{
    int choice,data,n,i=1;
    struct node *root=NULL;
    while (1)
    {
        printf("\nEnter 1 to craete the one way right threaded BST:\n");
        printf("Enter 2 to transverse the elements in INORDER:\n");
        printf("Enter 3 to insert data in Right threaded BST:\n");
        printf("Enter 4 to exit:\n");
        printf("Enter your choice:...\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of elements you want to create a one way right threaded BST:\n");
            scanf("%d",&n);
            while (n>0)
            {
                printf("\nEnter the element %d to be inserted : ",i);
                scanf("%d",&data);
                root = insertelement(root,data);
                i++;
                n--;
            }
            break;
        case 2:
            inorderbst(root);
            break;
        case 3:
            printf("\nEnter the element %d to be inserted : ",i);
            scanf("%d",&data);
            i++;
            root = insertelement(root,data);
            printf("\nElement is inserted\nGo and CHECK in INORDER transversal\n");
            break;
        case 4:
            printf("You entered to exit from program......\nTHANK YOU\n");
            exit(1);
        
        default:
            printf("\nWrong choice\n");
            break;
        }
    }
}