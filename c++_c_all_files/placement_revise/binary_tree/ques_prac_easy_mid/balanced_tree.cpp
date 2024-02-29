//approch - 1 time complexity - O(n^2) as repeatedly we have to call height function taking O(n)

int height(Node *root){
    if(root == NULL){
        return 0;
    }
    int h = max(height(root->left), height(root->right)) + 1;
    return h;
}

bool isBalanced(Node *root)
{
    if(root == NULL){
        return true;
    }
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    if(left && right && diff ){
        return true;
    }
    return false;
}

//approch - 2 time complexity - O(n)

pair<int,bool> height(Node *root){
    if(root == NULL){
        return {0,1};
    }
    pair<int,bool>  hl = height(root->left);
    pair<int,bool>  hr = height(root->right);
    pair<int,bool> h;
    h.first = max(hl.first,hr.first)+1;
    if((abs(hl.first-hr.first) <= 1) && hl.second && hr.second){
        h.second = true;
    }
    else{
        h.second = false;
    }
    return h;
}