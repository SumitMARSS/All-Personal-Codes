#include<stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *root=NULL;
struct node *loc , *parent , *save;
struct node *deleteanodebst(struct node *root, int item)
{
    struct node *ptr2 = root;
    struct node *prev = NULL;

    if (ptr2 == NULL)
    {
        printf("Data not found!!!");
        return root;
    }

    while (ptr2 != NULL && ptr2->data != item)
    {
        prev = ptr2;
        if (item < ptr2->data)
            ptr2= ptr2->left;
        else
            ptr2 = ptr2->right;
    }

    if (ptr2->left == NULL || ptr2->right == NULL)
    {
        struct node *cur1;
        if (ptr2->left == NULL)
        {
            cur1 = ptr2->right;
        }
        else
        {
            cur1 = ptr2->left;
        }
        if (prev == NULL)
            return cur1;

        if (ptr2 == prev->left)
            prev->left = cur1;
        else
            prev->right = cur1;
        free(ptr2);
    }
    else
    {
        struct node *p = NULL;
        struct node *temp;
        temp = ptr2->right;
        while (temp->left != NULL)
        {
            p = temp;
            temp = temp->left;
        }
        if (p != NULL)
            p->left = temp->right;
        else
            ptr2->right = temp->right;
        ptr2->data = temp->data;
        free(temp);
    }
    return root;
}

struct node *search_element(struct node *root, int value)
{
    int x = 0;
    struct node *save, *ptr;
    if (root == NULL)
    {
        loc = NULL;
        parent = NULL;
    }
    if  (value == root->data)
    {
        x++;
        loc = root;
        parent = NULL;
        printf("Parent is at Location %d \n Parent value is %d\n",x-1,parent->data);
        printf("Location is at %d\n", x);
        return root;
    }
    if  (value < root->data)
    {
        x++;
        save = root;
        ptr = root->left;
    }
    else
    {
        x++;
        save = root;
        ptr = root->right;
    }
    while (ptr != NULL)
    {
        x++;
        if (ptr->data == value)
        {
            loc = ptr;
            parent = save;
            printf("Parent is at Location %d and parent data is %d\n",x-1,parent->data);
            printf("Location is at %d\n", x);
            return root;
        }
        if (value < ptr->data)
        {
            save = ptr;
            ptr = ptr->left;
        }
        else
        {
            save = ptr;
            ptr = ptr->right;
        }
    }
    loc = NULL;
    parent = save;
    return root;
}

struct node *create(struct node *root,int value)
{
	struct node *parentptr;
	struct node *nodeptr;
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{
		root=newnode;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		parentptr=NULL;
  		nodeptr=root;
  		while(nodeptr!=NULL)
  			{
  				parentptr=nodeptr;
  				if(value<nodeptr->data)
				{
					nodeptr=nodeptr->left;
				}
  				else
				{
					nodeptr=nodeptr->right;
				}
  			}
  		if(value<parentptr->data)
		{
			parentptr->left=newnode;
		}
  		else
		{
			parentptr->right=newnode;
		}
	}
return root;
}

int biggest(struct node *root)
{
int value;
struct node *ptr=root;
while(ptr->right!=NULL)
{
ptr=ptr->right;
}
value=ptr->data;
return value;
}

int smallest(struct node *root)
{
int value;
struct node *ptr=root;
while(ptr->left!=NULL)
{
ptr=ptr->left;
}
value=ptr->data;
return value;
}

void inorder_traversal(struct node *root)
{
if(root!=NULL)
{
inorder_traversal(root->left);
printf("%d\t",root->data);
inorder_traversal(root->right); 
}
}

int main()
{
	int option,value;
	struct node *ptr;
	do
	{
	printf("\n*****-----Menu----*****\n");
	printf("1.Create a Binary Search Tree:\n");
	printf("2. To find smallest element...:\n");
  	printf("3. To find biggest element:....\n");
	printf("4. To search a node in Binary Search Tree:\n");
	printf("5. To delete a node in Binary Search Tree:\n");
	printf("6. Inorder traversal:...\n");
	printf("7. To Exit from the program....:\n");
	printf("Enter your option...:\n");
	scanf("%d",&option);
	switch(option)
	{
  		case 1:
		printf("Enter the value:..\nEnter -1 if you don't want to enter data...\n");
        scanf("%d",&value);
			do
			{
				root=create(root,value);
				printf("Enter the value:..\nEnter -1 if you don't want to enter data...\n");
        		scanf("%d",&value);
			} while (value!=-1);
        break;
		case 2:value=smallest(root);
        	printf("Smallest number in the Binary search Tree is = %d\n",value);
        break;
  		case 3:value=biggest(root);
        	printf("Biggest number in the Binary search Tree is = %d\n",value);
        break;
  		case 4:
            printf("\nEnter value you want to search:  ");
            scanf("%d", &value);
            root = search_element(root,value);
            if (loc != NULL)
            {
                printf("%d is founded in Binary Search Tree\n", value);
            }
            else
            {
                printf("\nItem is not present in Binary Search Tree\n");
            }
        break;
		case 5:
            printf("\nEnter value you want to delete:  ");
            scanf("%d", &value);
            root = deleteanodebst(root, value);
			printf("Your item is deleted....\nGo and check by chosing option 6...\n");
        break;
		break;
		case 6:
			printf("Your items in inorder traversal are...\n");
			inorder_traversal(root);
        break;
		case 7:
			printf("You have entered to take Exit from program...\n'THANK YOU...\n");
			exit(0);
		default:
			printf("You have entered 'INVALID INPUT'...\n");
			break;	
	}
}while(option!=10);
return 0;
}

void delabst(struct node *root, int value)
{
	struct node *child, *ptr1;
	ptr1=search_element(root , value);
	if (loc->left==NULL && loc->right==NULL)
	{
		child=NULL;
	}
	else
	{
		if (loc->left!=NULL)
		{
			child=loc->left;
		}
		else
		{
			child=loc->right;
		}
	}
	if (parent=NULL)
	{
		root=child;
	}
	else
	{
		if (loc=parent->left)
		{
			parent->left=child;
		}
		else
		{
			parent->right=child;
		}
	}
}

void delcbst(struct node *root, int value)
{
	struct node *suc, *parsuc, *ptr, *ptr1, *ptr2;
	ptr1=search_element(root, value);
	ptr = loc->right;
	save= loc;
	while (ptr->left!=NULL)
	{
		save=ptr;
		ptr=ptr->left;
	}
	suc=ptr;
	parsuc=save;
	delabst(root, value);
	if (parent!=NULL)
	{
		if (loc=parent->left)
		{
			parent->left=suc;
		}
		else
		{
			parent->right=suc;
		}
	}
	else
	{
		root=suc;
	}
	suc->left=loc->left ;
	suc->right=loc->right;
}

void delbst(struct node *root, int value)
{
	struct node *ptr1 , *ptr;
	ptr1=search_element(root,value);
	if (loc==NULL)
	{
		printf("Item not found...\n");
	}
	if (loc->right!=NULL && loc->left!=NULL)
	{
		delcbst(root,value);
	}
	else
	{
		delabst(root,value);
	}
	loc->left=ptr;
	ptr=loc;
}