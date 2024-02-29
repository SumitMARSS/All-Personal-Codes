#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node *next;
    node *prev;
    node (int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void insert_at_head_dblinklist(node *&head,int val){
    node *newnode = new node(val);
    newnode->next = head;
    if (head!=NULL)
    {
        head->prev = newnode;   
    }
    head = newnode;
}

void add_last_doubly_linklist(node *&head,int val){
    node *newnode = new node(val);
    if (head==NULL)
    {
        insert_at_head_dblinklist(head,val);
        return;
    }
    node *ptr = head;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next = newnode;
    newnode->prev = ptr;
    return;
}

void display(node *head){
    node *ptr = head;
    while (ptr!=NULL)
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL\n";
}

void delete_at_head(node *&head){
    node *ptr = head;
    head = head->next;
    head->prev = NULL;
    delete ptr;
}

void delete_at_pos(node *&head , int pos){
    node *ptr = head;
    //node *todelete;
    if (pos == 1)
    {
        delete_at_head(head);
        return;
    }
    
    int count = 1;
    while (ptr!=NULL && count!=pos)
    {
        ptr=ptr->next;
        count++;
    }
    //todelete = ptr->next;
    //ptr->next = ptr->next->next; //like singly link list
    //for doubly list as we can acess both next and prev

    ptr->prev->next = ptr->next;//last point is deleted only because of this statement
    if (ptr->next!=NULL)
    {
        ptr->next->prev = ptr->prev;
    }
    delete ptr;
}

int length(node *head){
    node *ptr = head;
    int l= 0;
    while (ptr!=NULL)
    {
        l++;
        ptr=ptr->next;
    }
    return l;
}

node* append_last_k(node *&head,int k){
    node *tail = head;
    node *newhead;
    node *newtail;
    int l = length(head);
    k=k%l;//if k given is more than l
    int count=1;
    while (tail->next!=NULL)
    {
        if (count == (l-k))
        {
            newtail = tail;
        }
        else if (count == (l-k)+1)
        {
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }
    newtail->next = NULL;
    tail->next = head;
    return newhead;
    
}

int main(){
    node *head = NULL;
    node *newhead;
    int n,val,val1,pos,k=3;
    cout<<"Enter the number of data you want to add in doubly link list\n";
    cin>>n;
    while (n--)
    {
        cout<<"Enter the val you want to add\n";
        cin>>val;
        add_last_doubly_linklist(head,val);
    }
    display(head);
    cout<<"Enter the val you want to add at starting\n";
    cin>>val1;
    insert_at_head_dblinklist(head,val1);
    display(head);
    cout<<"Enter the pos to delete the node\n";
    cin>>pos;
    delete_at_pos(head,pos);
    display(head);
    newhead= append_last_k(head,k);
    display(newhead);
    
}

