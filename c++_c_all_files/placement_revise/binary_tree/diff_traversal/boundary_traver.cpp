//left traversal except leaf node
    
void traverse_left(Node *root,vector<int>& ans){
    //base case and if we get leaf node then return
    if( (root == NULL) || (root->left == NULL && root->right == NULL ) ) {
        return;
    }
    //put data in ans
    ans.push_back(root->data);
    if(root->left != NULL){
        traverse_left(root->left, ans);
    }
    else{
        traverse_left(root->right, ans);
    }
}

void leaf_traversal(Node *root , vector<int>& ans){
    if(root == NULL){
        return ;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }
    //explore left and right subtree for leaf node
    leaf_traversal(root->left,ans);
    leaf_traversal(root->right,ans);
}

void traverse_right(Node *root , vector<int>& ans){
    //base case and if we get leaf node then return
    if( (root == NULL) || (root->left == NULL && root->right == NULL ) ) {
        return;
    }
    //first went to last right node before leaf
    if(root->right != NULL){
        traverse_right(root->right,ans);
    }
    else{
        traverse_right(root->left,ans);
    }
    ans.push_back(root->data);
}

vector <int> boundary(Node *root)
{
    vector<int>ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->data);
    //left traversal
    traverse_left(root->left ,ans);
    //leaf node traversal
    
    //in left subtree
    leaf_traversal(root->left,ans);
    //in right subtree
    leaf_traversal(root->right,ans);
    
    //right traversal but first go till lastest right subtree before leaf
    traverse_right(root->right,ans);
    
    return ans;
}