#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
int a[50],x=0,sum,y=0,t,top=0;
struct  node *stack[50];

struct node *createbst(struct node *root,int item)
{
	struct node *newnode,*ptr, *ptr1;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Underflow\n");
		exit(0);
	}
	newnode->data=item;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{
		root=newnode;
	}
	else
	{
		ptr=root;
		ptr1=NULL;
		while(ptr!=NULL)
		{
			ptr1=ptr;
			if(item<=ptr->data)
			{
				ptr=ptr->left;
			}
			else
			{
				ptr=ptr->right;
			}
		}
		if(item<ptr1->data)
		{
			ptr1->left=newnode;
		}
		else
		{
			ptr1->right=newnode;
		}
	}
	return root;
}
struct node *inorder(struct node *root)
{
	struct node *ptr;
	stack[top]=NULL;
	ptr=root;
	while(ptr!=NULL)
	{
		top=top+1;
		stack[top]=ptr;
		ptr=ptr->left;
	}
	ptr=stack[top];
	top=top-1;
	while(ptr!=NULL)
	{
		a[x]=ptr->data;
		x++;
		if(ptr->right!=NULL)
		{
			ptr=ptr->right;
			while(ptr!=NULL)
			{
				top=top+1;
				stack[top]=ptr;
				ptr=ptr->left;
			}
		}
		ptr=stack[top];
		top=top-1;
	}
	return root;
}

int main()
{
	int data ,i,j, sum=0;
	struct node *root=NULL;
	struct node *c;
	printf("Enter -1 to terminate\n");
	printf("Enter the data \n");
	scanf("%d",&data );
	while(data !=-1)
	{
		root=createbst(root,data );
		printf("Enter the data \n");
		scanf("%d",&data );
	}
	printf("Binary tree is created.....\n\n");
	printf("Inorder traversal for binary tree:\n");
	inorder(root);
	for(i=0;i<x;i++)
	{
		printf("%d ",a[i]);
        sum+=a[i];
	}
    printf("\n");
    printf("New inorder traversal of modified binary tree is:\n");
	printf("\n");
    for(i=0;i<x;i++)
	{
		printf("%d ",sum);
        sum-=a[i];
	}
	inorder(root);
}