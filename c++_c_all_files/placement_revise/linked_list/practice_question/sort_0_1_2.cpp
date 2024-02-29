// approch 1

Node* sortList(Node *head){
    // Write your code here.
    Node *ptr = head;
    int zero_count = 0;
    int ones_count = 0;
    int twos_count = 0;

    while(ptr != NULL){
        if(ptr->data == 0){
            zero_count++;
        }
        if(ptr->data == 1){
            ones_count++;
        }
        if(ptr->data == 2){
            twos_count++;
        }
        ptr = ptr->next;
    }

    //approch replacement
    ptr = head;
    while(ptr != NULL){
        while(zero_count--){
            ptr->data = 0;
            ptr = ptr->next;
        }
        while(ones_count--){
            ptr->data = 1;
            ptr = ptr->next;
        }
        while(twos_count--){
            ptr->data = 2;
            ptr = ptr->next;
        }
    }

    //approch new list again link
    
    return head;
}

//approch 2

void insert_at_tail(Node *&tail,Node * ptr){
    tail->next = ptr;
    tail = ptr;
}

Node* sortList(Node *head){
    // Write your code here.
    //approch new list geration
    Node *zero_head = new Node(-1);
    Node *zerotail = zero_head;
    Node *one_head = new Node(-1);
    Node *onetail = one_head;
    Node *two_head = new Node(-1);
    Node *twotail = two_head;
    
    //created 3 different list of 0,1,2
    Node * ptr = head;
    while(ptr!= NULL){
        int value = ptr->data;
        if(value == 0){
            insert_at_tail(zerotail,ptr);
        }
        else if(value == 1){
            insert_at_tail(onetail,ptr);
        }
        else if(value == 2){
            insert_at_tail(twotail,ptr);
        }
        ptr = ptr->next;
    }
    //merge all 3 list
    if(one_head->next != NULL){
        //one list not empty
        zerotail->next = one_head->next;
    }
    else{
        //one list is empty
        zerotail->next = two_head->next;
    }
    onetail->next = two_head->next;
    twotail->next = NULL;
    
    head = zero_head->next;
    
    //delete all dummy nodes
    delete zero_head;
    delete one_head;
    delete two_head;
    return head;
}