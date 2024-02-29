#include <iostream>
#include <queue>
using namespace std;
class node{
    public:
    int data;
    node * left;
    node * right;

    node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insert_at_bst(node* root, int data){
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insert_at_bst(root->right,data);
    }
    else{
        root->left = insert_at_bst(root->left,data);
    }
    return root;
}

void take_input(node* &root){
    int data;
    cout<<"Enter the data (-1 to exit)"<<endl;
    cin>>data;
    while (data != -1)
    {
        root  = insert_at_bst(root,data);
        cout<<"Enter the data (-1 to exit)"<<endl;
        cin>>data;
    }
    return;
}

void levelOrderTraversal(node *root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            //we have traversed level 0
            cout<<endl;
            if (!q.empty())
            {
                //in queue there is still childs
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

int main(){
    node* root = NULL;
    take_input(root);
    cout<<"Your level order traversal are: "<<endl;
    levelOrderTraversal(root);
}