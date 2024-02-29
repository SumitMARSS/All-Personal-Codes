
//Approch - 1 ->> calculating diameter but Time complexity - O(n^2) as 
// we have to find height every time when we are calculating diameter for left and right


int height(Node* root){
        if(root == NULL){
            return 0;
        }
        int left = height(root->left);//height of left tree
        int right = height(root->right);//height of right tree
        int h = max(left,right)+1;
        return h;
    }
    
int diameter(Node* root) {
    if(root == NULL){
        return 0;
    }
    int opt_1 = height(root->left) + height(root->right) +1;
    int opt_2 = diameter(root->left);
    int opt_3 = diameter(root->right);
    
    return max(opt_1,max(opt_2,opt_3));
}

//can we reduce this ??????????/

pair<int,int> fast_diameter(Node* root){
    //base case
    if(root == NULL){
        return {0,0};
    }
    //calculating diameter and height for left and right sub tree
    pair<int,int> left_tree = fast_diameter(root->left);
    pair<int,int> right_tree = fast_diameter(root->right);
    //we have 3 options to find diameter 
    // Max diameter may be directly lie in left or right subtree
    int opt1 = left_tree.first;
    int opt2 = right_tree.first;
    //Max height of left + right + 1 may be total diameter
    int opt3 = left_tree.second + right_tree.second +1;
    pair<int,int> ans;
    ans.first = max(opt1, max(opt2,opt3)); //its diameter
    ans.second = max(left_tree.second, right_tree.second)+1;
    return ans;
}