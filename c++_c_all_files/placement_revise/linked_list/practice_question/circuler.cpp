//approch 1

bool isCircular(Node * head) {
    // If head is already NULL, then it is the circular linked list
    // with length zero.
    if (head == NULL) {
        return true;
    }

    // If next pointer of head is already NULL, then it the linear linked
    // list of length 1, hence we return false here.
    if (head -> next == NULL) {
        return false;
    }

    // Initialising slow and fast pointers with head.
    Node * slow = head, * fast = head;

    // Iterating through the linkedlist till, fast doesn't reach end of 
    // linked list or slow pointer will not become equal to fast pointer.
    while (fast != NULL && fast -> next != NULL) {

        // Moving slow pointer by one step.
        slow = slow -> next;
        // Moving fast pointer by two steps.
        fast = fast -> next -> next;

        // Checking if updated slow and fast pointer values are same or not.
        if (slow == fast) {
            break;
        }

    }

    // After completing the traversal, if slow and fast pointers meet and 
    // the node of meeting is node pointed by head, then linkedlist is circular.
    if (slow == fast && slow == head) {
        return true;
    }

    // If linkedlist is not circular, then return false.
    return false;
}
 
//approch 2
//deleting prev node as we are going forward

bool isCircular(Node* head)
{
    if(head==NULL) return true;
    Node*prev = head;
    Node*temp = head->next;
    while(temp != head && temp!= NULL)
    {
        prev->next=NULL;
        prev=temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        return false;
    }
    else{
        return true;;
    }
}

//approch 3
//we are checking the frequency of our data if it is greater then 0 
//it means we have a node with same data as not circuler according to given condn

bool isCircular(Node* head){

    if(head == NULL)return true;
     if (head -> next == NULL) {
        return false;
    }
    Node* itr = head ->next;

    unordered_map<int,int> mp;

    while(itr!= NULL){

        if(itr == head) return true;
        if(mp[itr->data] > 0) return false;

        mp[itr->data]++;
        itr = itr->next;
    }

    return false;
}