pair<int,bool>find_sum_with_prev_data(Node* root){
    
    if(root == NULL){
        return {0,true};
    }
    if(root->data!= NULL && root->left == NULL && root->right == NULL){
        return {root->data,true};
    }

    pair<int,bool>left = find_sum_with_prev_data(root->left);
    pair<int,bool>right = find_sum_with_prev_data(root->right);
    // int sum = root->data + left.first + right.first; same as

    int sum = 2*root->data;
    
    if( (root->data == left.first + right.first ) && left.second && right.second ){
        return {sum,true};
    }
    else{
        return {sum,false};
    }
}

bool isSumTree(Node* root)
{
    return find_sum_with_prev_data(root).second;
}