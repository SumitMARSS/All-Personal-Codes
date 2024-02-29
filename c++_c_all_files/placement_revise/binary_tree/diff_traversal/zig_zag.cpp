vector <int> zigZagTraversal(Node* root)
{
    vector<int>result;
    //if root is NULL return
    if(root == NULL){
        return result;
    }
    
    queue<Node*>q;
    q.push(root);
    
    bool left_to_right = true;
    
    while(!q.empty()){
        int size = q.size();
        vector<int>temp_arr(size);
        //traverse whole level and push eleemnt in order either L---R or R---l
        
        for(int i=0; i<size; i++){
            //front_node of queue
            Node* front_node = q.front();
            q.pop();
            if(left_to_right){   //store in array from  first to last
                temp_arr[i] = front_node->data;
            }
            else{   //store in array from last to first
                temp_arr[size-i-1] = front_node->data;
            }
            
            //push child node if we pop any parent node

            if(front_node->left != NULL){
                q.push(front_node->left);
            }
            if(front_node->right != NULL){
                q.push(front_node->right);
            }
        }
        //change the direction
        left_to_right = !left_to_right;
        
        //push in final result array
        for(auto i: temp_arr ){
            result.push_back(i);
        }
    }
    return result;
}