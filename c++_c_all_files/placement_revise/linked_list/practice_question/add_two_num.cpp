class Solution
{
    Node *reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* ptr;
        while(curr != NULL){
            ptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ptr;
        }
        return prev;
    }
    
    void insert_at_tail(Node *&head,int rem){
        
        Node *newnode = new Node(rem);
        if(head == NULL){
            head = newnode;
            return;
        }
        Node *ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }

     //optimizing the list

    Node* add_twoLL(Node *first, Node* second){
        Node* head1 = first;
        Node* head2 = second;
        Node* head = NULL;
        
        int carry = 0;
        int sum=0,rem=0;
        
        while(head1 != NULL || head2!=NULL || carry!=0 ){
            int val1 = 0;
            int val2 = 0;
            if(head1 != NULL){
                val1 = head1->data;
            }
            if(head2 != NULL){
                val2 = head2->data;
            }
            sum = val1 + val2 + carry;
            rem = sum%10;
            insert_at_tail(head,rem);
            carry = sum/10;
            if(head1 != NULL){
                head1=head1->next;
            }
            if(head2 != NULL){
                head2 = head2->next;
            }
        }
       return head;
    }
    
    // Node* add_twoLL(Node *first, Node* second){
    //     Node* head1 = first;
    //     Node* head2 = second;
    //     Node* head = NULL;
        
    //     int carry = 0;
    //     int sum=0,rem=0;
        
    //     while(head1 != NULL && head2!=NULL){
    //         sum = head1->data + head2->data + carry;
    //         rem = sum%10;
    //         insert_at_tail(head,rem);
    //         carry = sum/10;
    //         head1=head1->next;
    //         head2 = head2->next;
    //     }
    //    while(head1 != NULL || head2!= NULL){
    //        if(head1 !=NULL){
    //             sum = head1->data + carry;
    //             rem = sum%10;
    //             insert_at_tail(head,rem);
    //             carry = sum/10;
    //             head1=head1->next;
    //        }
    //        if(head2!=NULL){
    //             sum = head2->data + carry;
    //             rem = sum%10;
    //             insert_at_tail(head,rem);
    //             carry = sum/10;
    //             head2=head2->next;
    //        }
    //    }
    //    if(carry!=0 ){
    //        insert_at_tail(head,carry);
    //    }
    //    return head;
    // }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        //step 1 reverse the lists
        first = reverse(first);
        second = reverse(second);
        //step 2 add
        Node* ans = add_twoLL(first,second);
        //step 3
        ans = reverse(ans);
        return ans;
    }
};