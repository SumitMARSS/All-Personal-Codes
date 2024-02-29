//my approch

void insertattail(Node<int>* &tail, Node<int>* ptr){
    tail->next = ptr;
    tail = ptr;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* head;
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }
    Node<int>* dummy_Node = new Node<int>(-1);
    Node<int>* dummytail = dummy_Node;
    while(first != NULL && second != NULL){
        int val1 = first->data;
        int val2 = second->data;
        if(val1 >= val2){
            insertattail(dummytail,first);
            first = first->next;
        }
        else{
            insertattail(dummytail,second);
            second = second->next;
        }
    }
    if(first == NULL){
        dummytail->next = second;
    }
    else if(second == NULL){
        dummytail->next = first;
    }
    head = dummy_Node->next;
    delete dummy_Node;
    return head;
}


Node<int>* curr = first->next;
    Node<int>* prev = first;
    while(curr != NULL){
        int val = second->data;
        Node<int>* ptr = second;
        if(val >= prev->data && val <= curr->data){
            prev->next = ptr;
            ptr->next = curr;
            prev = ptr;
            second = second->next;
        }else{
            prev = prev->next;
            curr = curr->next;
        }
    }
    if(second!=NULL){
        curr = second;
    }
    return first;

// sir approch - 1

