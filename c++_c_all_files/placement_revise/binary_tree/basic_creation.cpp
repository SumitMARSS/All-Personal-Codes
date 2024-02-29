#include <iostream>
#include <queue>
using namespace std;

//creating a node
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node *create_binary_tree(node *root){
    cout<<"Enter the data -> "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    //base case
    if (data == -1)
    {
        return NULL;
    }
    cout<<"Enter the left node -> "<<endl;
    root->left = create_binary_tree(root->left);
    cout<<"Enter the right node -> "<<endl;
    root->right = create_binary_tree(root->right);
    return root;
}

//use seperator NULL to diffirentiate between level and if we get seperator then press ENTER(endl)
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

void PreorderTraversal(node * root){
    //base case 
    if (root == NULL)
    {
        return;
    }
    // Node Left Right
    cout<<root->data<<" ";  //node
    PreorderTraversal(root->left); //left
    PreorderTraversal(root->right); //right
}

void InorderTraversal(node * root){
    //base case 
    if (root == NULL)
    {
        return;
    }
    // Left Node Right
    InorderTraversal(root->left); //left
    cout<<root->data<<" ";  //node
    InorderTraversal(root->right); //right
}

void PostorderTraversal(node * root){
    //base case 
    if (root == NULL)
    {
        return;
    }
    // Left Right Node 
    PostorderTraversal(root->left); //left
    PostorderTraversal(root->right); //right
    cout<<root->data<<" ";  //node
}

void create_tree_from_level_order_tarversal(node *& root){
    queue<node*>q;
    cout<<"Enter data of root node -> "<<endl;
    int val;
    cin>>val;
    root = new node(val); //root node is created
    q.push(root);
    //enter in queue and enter data for left and right traversal
    while (!q.empty())
    {
        node*temp = q.front();
        q.pop();
        //enter data for left element
        cout<<" Enter data for left node ->"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if (leftdata!= -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        //enter data for right element
        cout<<" Enter data for right node ->"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if (rightdata!= -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
    
}

int main(){
    node *root = NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // root = create_binary_tree(root);
    // cout<<endl;
    // cout<<" Level order Traversal -> "<<endl;
    // levelOrderTraversal(root);
    // cout<<"\n Preorder Traversal -> "<<endl;
    // PreorderTraversal(root);
    // cout<<"\n Inorder Traversal -> "<<endl;
    // InorderTraversal(root);
    // cout<<"\n Postorder Traversal -> "<<endl;
    // PostorderTraversal(root);

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    create_tree_from_level_order_tarversal(root);
    cout<<" Level order Traversal -> "<<endl;
    levelOrderTraversal(root);
}