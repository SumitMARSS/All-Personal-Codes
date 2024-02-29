#include <bits/stdc++.h>
using namespace std;

//using encapsulation as a node just to encapsule (data and next) -> data member
class node {
    public:
    int data;
    node * next;
    //parametrised constructor -> if we didn't use this constructor a default constructor is used
    node(int val){
        this->data = val;
        this->next = NULL;
    }
};

//reference is used as we are not returning anything
void insertion_at_end(node *&head,int val){
    node *newnode = new node(val);
    node *ptr = head;
    if (ptr == NULL)
    {
        head = newnode;
        return;
    }
    while (ptr ->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
}

void insertion_at_head(node *&head,int val){
    node *newnode = new node(val);
    newnode->next = head;
    head = newnode;
}




void print(node *ptr){
    while (ptr != NULL)
    {
        cout<< ptr->data <<" -> ";
        ptr = ptr->next;
    }cout<<"NULL"<<endl;
}

void make_circle(node *&head){
    //just to check our sol (no corner will be checked)
    node *ptr = head;
    node *ptr1 = head->next->next->next; //check for corner
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next = ptr1;
}

node* find_start_loop(node * head){
    if (head == NULL)
    {
        return head;
    }
    
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            cout<<" slow and fast detected at -> "<<fast->data<<endl;
            break;
        }
    }
    //corner case
    // if (fast == NULL || fast->next == NULL) {
    //     cout << "No cycle detected." << endl;
    //     return;
    // }
    ///point slow at head


    //here we can get fast and slow by ffloyd algo
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    cout<<" Cycle start at -> "<<fast->data<<endl;
    return fast;
}

void remove_loop(node*&head, node *&start_circle){
    if (head == NULL)
    {
        return;
    }
    node *ptr = start_circle->next;
    while (ptr->next != start_circle)
    {
        ptr = ptr->next;
    }
    ptr->next = NULL;
}

bool detect_cycle_floyd(node *head){
    node *slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL) // always fast will be forward that's why we check fast
    {
        fast = fast->next->next; //one more condn is added only bec's of this line
        slow =  slow->next;
        if (fast == slow)
        {
            return true; // for only circuler linked prob you have to add only one condn like fast == head
        }
    }
    return false;
}

int main(){

    node * head = NULL;
    int n;
    cout<<"Enter the no of elements you want in end of link list -> "<<endl;
    cin>> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout<<"Data "<<i+1<<" ";
        cin>>val;
        insertion_at_end(head,val);
    }
    print(head);
    make_circle(head);
    
    bool is_cycle = detect_cycle_floyd(head); 
    if (is_cycle)
    {
        cout<<" cycle is present "<<endl;
    }
    else
    {
        cout<<" cycle is not present "<<endl;
    }
    node *start_circle = find_start_loop(head);
    remove_loop(head,start_circle);
    is_cycle = detect_cycle_floyd(head); 
    if (is_cycle)
    {
        cout<<" cycle is present "<<endl;
    }
    else
    {
        cout<<" cycle is not present "<<endl;
    }
    print(head);
}



/*

//check logics

Node *detect_meet(Node *head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return NULL;
    }
    //floyd algo
    Node *fast = head;
    Node *slow = head;
    while(fast != NULL && fast->next != NULL){
        fast=fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return fast;
        }
    }
    if(fast == NULL || fast->next == NULL)
    return NULL;
}

Node *check_start(Node *head,Node *meet){
    Node *fast = meet;
    Node *slow = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

void removeLoop_list(Node *&head, Node* loop_start){
    if(head == NULL){
        return;
    }
    Node *ptr = loop_start->next;
    while(ptr->next != loop_start){
        ptr = ptr->next;
    }
    ptr->next = NULL;
}

Node *removeLoop(Node *head)
{
    // Write your code here.
    if(head->next == head){
        head->next =NULL;
    }
    Node *meet = detect_meet(head);
    if(meet == NULL){
        return head;
    }
    Node *loop_start = check_start(head,meet);
    removeLoop_list(head,loop_start);
    return head;
}


*/