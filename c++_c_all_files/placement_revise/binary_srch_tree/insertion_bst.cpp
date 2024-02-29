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

int find_min(node* root){
    node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

int find_max(node* root){
    node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

node* delete_a_node_from_bst(node* root,int data){
    //base case
    if (root == NULL)
    {
        return NULL;
    }
    //2 base case
    if(root->data == data){

        //0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        
        //1 child
        //left subtree
        else if (root->left != NULL && root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        //right subtree
        else if (root->left == NULL && root->right != NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        else{
            int mini = find_min(root->right);
            root->data = mini;
            root->right = delete_a_node_from_bst(root->right,mini);
            return root;
        }
    }
    else if (root->data > data)
    {
        root->left = delete_a_node_from_bst(root->left,data);
    }
    else
    {
        root->right = delete_a_node_from_bst(root->right, data);
    }
    return root;
}

int main(){
    node* root = NULL;
    take_input(root);
    cout<<"Your level order traversal are: "<<endl;
    levelOrderTraversal(root);
    // 15 10 20 8 9 17 25 6 7 16 19 -1
    cout<<"Minimum element in tree are : "<<find_min(root)<<" "<<endl;
    cout<<"Maximum element in tree are : "<<find_max(root)<<" "<<endl;
    while (1)
    {
        int data;
        cout<<"Enter the node to delete ( Enter -1 to exit )"<<endl;
        cin>>data;
        if (data == -1)
        {
            break;
        }
        root = delete_a_node_from_bst(root,data);
        cout<<"your node is deleted ........ "<<endl;
        cout<<"Your level order traversal are: "<<endl;
        levelOrderTraversal(root);
    }
    return 0;
}