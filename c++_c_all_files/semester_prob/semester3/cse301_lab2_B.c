#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node* left;
    struct node* right;
};

int sum=28;
struct node* newnode(int key)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
 
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->key);
    printInorder(node->right);
}

void printModifyInorder(struct node* node )
{ 
    if (node == NULL)
        return;
    printModifyInorder(node->left);
    printf("%d ", sum);
    sum -= node->key;
    printModifyInorder(node->right);
}

int main()
{
    struct node *root = newnode(4);
    root->left = newnode(2);
    root->right = newnode(6);
    root->left->left = newnode(1);
    root->left->right = newnode(3);
    root->right->left = newnode(5);
    root->right->right = newnode(7);
    
 
    printf("Inorder traversal of the given tree\n");
    printInorder(root);
 
    printf("\nInorder traversal of the modified tree\n");
    printModifyInorder(root);
 
    return 0;
}

