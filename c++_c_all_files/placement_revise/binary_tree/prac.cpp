#include<iostream>
#include<queue>
using namespace std;

//creation of a node
class node{
    public:
    int data;
    node *left;
    node *right;
    node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node *create_binary_tree(node * root){
    cout<<"Enter the data -> "<<endl;
    int val;
    cin>>val;
    root = new node(val);
    if (val == -1)
    {
        return NULL;
    }
    //Add leftnode by recursion
    cout<<"Enter the data for left node -> "<<endl;
    root->left = create_binary_tree(root->left);
    //Add rightnode by recursion
    cout<<"Enter the data for right node -> "<<endl;
    root->right = create_binary_tree(root->right);
    return root;
}

void level_order_traversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout<<endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

void preorder_traversal(node *root){
    //Node    Left    Right
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(node *root){
    //  Left  Node  Right
    if (root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}

void postorder_traversal(node *root){
    // Left    Right   Node    
    if (root == NULL)
    {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";
}

void create_tree_from_level_order(node *&root){
    cout<<"Enter data for root node -> "<<endl;
    int val;
    cin>>val;
    root = new node(val);
    queue<node *>q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        int leftval;
        cout<<" Enter left value of "<<temp->data<<endl;
        cin>>leftval;
        if (leftval != -1)
        {
            temp->left = new node(leftval);
            q.push(temp->left);
        }
        int rightval;
        cout<<" Enter right value of "<<temp->data<<endl;
        cin>>rightval;
        if (rightval != -1)
        {
            temp->right = new node(rightval);
            q.push(temp->right);
        }
    }
}

int main(){
    node *root = NULL;
    // root = create_binary_tree(root);
    // cout<<"Level order traversal -> "<<endl;
    // level_order_traversal(root);
    // cout<<"\npreorder_traversal -> "<<endl;
    // preorder_traversal(root);
    // cout<<"\ninorder_traversal -> "<<endl;
    // inorder_traversal(root);
    // cout<<"\npostorder_traversal -> "<<endl;
    // postorder_traversal(root);
    create_tree_from_level_order(root);
    cout<<"Level order traversal -> "<<endl;
    level_order_traversal(root);

    return 0;
}