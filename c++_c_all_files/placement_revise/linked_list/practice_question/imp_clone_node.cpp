// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// /* Link list Node */
// struct Node {
//     int data;
//     Node *next;
//     Node *arb;

//     Node(int x) {
//         data = x;
//         next = NULL;
//         arb = NULL;
//     }
// };



// } Driver Code Ends
class Solution
{
    void insert_at_end(Node *&head,int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = newnode;
            return;
        }
        Node* ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }

    public:
    Node *copyList(Node *head)
    {
        //Write your code hereN
        Node * ptr = head;
        Node * clone = NULL;
        //step 1 -> simply clone the next simple link list
        while(ptr!=NULL){
            insert_at_end(clone,ptr->data);
            ptr= ptr->next;
        }
        //step 2 create a mapping from original node to reverse node
        unordered_map <Node* ,Node* >original_to_clone;
        ptr = head;
        Node* new_clone = clone;
        while(ptr != NULL){
            original_to_clone[ptr] = new_clone;
            ptr = ptr->next;
            new_clone = new_clone->next;
        }
        //generate random links of each node
        ptr = head;
        new_clone = clone;
        while(ptr!= NULL){
            new_clone->arb = original_to_clone[ptr->arb];
            new_clone = new_clone->next;
            ptr = ptr->next;
        }
        return clone;
    }

};

//finally ohhhhhhhhhhhhhhh
class Solution
{
    void insert_at_end(Node *&head,int val){
        Node *newnode = new Node(val);
        if(head == NULL){
            head = newnode;
            return;
        }
        Node* ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        Node *ptr = head;
        Node *clone = NULL;
        //step 1 copy the singly link list
        while(ptr != NULL){
            insert_at_end(clone,ptr->data);
            ptr = ptr->next;
        }
        //step -2
        Node *cloneNode = clone;
        ptr = head;
        while(ptr != NULL && clone != NULL){
            Node *next = ptr->next;
            ptr->next = cloneNode;
            ptr = next;
            
            Node *temp = cloneNode->next;
            cloneNode->next = ptr;
            cloneNode = temp;
        }
        //step -3 - connect random pointers
        
        Node *temp = head;
        while(temp != NULL){
            if(temp->next != NULL){
                if(temp->arb != NULL){
                    temp->next->arb = temp->arb->next;
                }
            }
            temp = temp->next->next;
        }
        //step - 4 //seperate links of next
        cloneNode = clone;
        ptr = head;
        while(ptr != NULL && cloneNode != NULL){
            ptr->next = cloneNode->next;
            ptr = ptr->next;
            if(ptr != NULL){
                cloneNode->next = ptr->next;
            }
            cloneNode = cloneNode->next;
        }
        return clone;
    }

};


//check error
class Solution
{
    void insert_at_end(Node *&head,int val){
        Node *newnode = new Node(val);
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
    
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        Node *clone = NULL;
        Node *ptr = head;
        //step 1 -> cloning simple link list only next
        while(  ptr!=NULL  ){
            insert_at_end(clone,ptr->data);
            ptr = ptr->next;
        }
        //step 2 -> create a list combing head and clone with mapping
        ptr = head;
        Node *new_clone = clone;
        
        while(ptr != NULL && new_clone!= NULL){
            //changing original nodes link
            Node *ptr_next = ptr->next;
            ptr->next = new_clone;
            ptr = ptr_next;
            //changing clone node links
            Node *clone_next = new_clone->next;
            new_clone->next = ptr;
            new_clone = clone_next;
        }
        //step - 3 link their random links on clone
        ptr = head;
        while(  ptr!= NULL){
            if(ptr->next != NULL){
                if(ptr->arb != NULL){
                    ptr->next->arb = ptr->arb->next;
                }
                else{
                    ptr->next = NULL;
                    //ptr->next = ptr->arb;
                }
            }
            ptr = ptr->next->next;
            
            
            
            //check further
            
            // new_clone->arb = ptr->arb->next;
            // ptr = ptr->next->next;
            // new_clone = new_clone->next->next;
        }
        //step 4 seperate their links so that we can get clone alone
        ptr = head;
        new_clone = clone;
        while(ptr != NULL && new_clone!= NULL){
            ptr->next = new_clone->next;
            ptr = ptr->next;
            if(ptr != NULL){
                new_clone = ptr->next;
            }
            new_clone = new_clone->next;
        }
        //step -5 return ans
        return clone;
    }

};