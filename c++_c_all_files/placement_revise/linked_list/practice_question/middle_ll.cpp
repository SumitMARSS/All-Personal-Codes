// approch 1

// find length of ll through traverse and then calculate mid and traverse till mid and return that ptr

Node *findMiddle(Node *head) {
    // Write your code here
    Node *ptr = head;
    Node *newnode = head;
    int count = 0;
    while(ptr !=NULL){
        count++;
        ptr = ptr->next;
    }
    count = count/2 ;
    while(count--){
        newnode=newnode->next;
    }
    return newnode;
}

//approch 2

//  a man A has speed 2X relative to man B having speed 1X then 
//  if ma =n A reach destination then B reached halfed of the way

//optimazation from last solution

Node *findMiddle(Node *head) {
    Node *ptr = head;
    Node *newnode = head;
    while(ptr != NULL ){
        if(ptr->next == NULL){
            break;
        }
        ptr = ptr->next->next;
        newnode = newnode->next;
    }
    return newnode;
}

//sir solution
Node *findMiddle(Node *head) {
    Node *ptr = head->next;
    Node *newnode = head;
    while(ptr != NULL ){
        ptr = ptr->next;
        //this is done to manage if ptr->next =NULL 
        if(ptr != NULL){
            ptr = ptr->next;
        }
        newnode = newnode->next;
    }
    return newnode;
}