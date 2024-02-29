#include <bits/stdc++.h>
using namespace std;

class dlnode{
    public:
    int data;
    dlnode *prev ;
    dlnode *next ;
    //parametrised constructor
    dlnode(int val){
        this->data = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insert_at_head(dlnode *& head, int val){
    dlnode *newnode = new dlnode(val);
    newnode->next = head;
    //head == NULL so we can't able to access prev of head so apply cond'n
    if (head != NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
}

void insert_at_end(dlnode *&head, int val){
    dlnode *ptr = head;
    dlnode *newnode = new dlnode(val);
    //first case
    if (head == NULL)
    {
        //insert_at_head(head,val);
        head = newnode;
        return;
    }
    //rest case
    
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->prev = ptr;
}

void insert_after_data(dlnode *& head,int val, int data){
    dlnode *ptr = head;
    dlnode *newnode = new dlnode(val);
    //head cond'n saved 
    if (head->data == data)
    {
        // head->prev = newnode;
        // newnode->next = head;
        // head = newnode;

    //directly we can say insertathead
        insert_at_head(head,val);
        return;
    }
    //for rest cond'n
    while (ptr->data != data)
    {
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next->prev = newnode;
    ptr->next = newnode;
    newnode->prev = ptr;
}

void delete_at_head(dlnode *& head,int val){
    dlnode *ptr = head;
    head = head->next;
    head->prev = NULL;
    delete ptr;
}

void deletion_of_node(dlnode *& head,int val){

    //first node to delete
    if (head->data == val)
    {
        delete_at_head(head,val);
        return;
    }
    //rest case
    dlnode *ptr = head;
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    //handle of last case
    if (ptr->next != NULL)
    {
        ptr->next->prev = ptr->prev;
    }
    ptr->prev->next = ptr->next;
    delete ptr;
}


void print(dlnode *head){
    while (head != NULL)
    {
        cout<<head->data<<" <=>";
        head= head->next;
    }
    cout<<" NULL "<<endl;
}

int main(){

    dlnode * head = NULL;

    //insert at end
    int n;
    cout<<"No of elements in DL link list to insert at end =>> "<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout<<"Data "<<i+1<<" ";
        cin>>val;
        insert_at_end(head,val);
    } 
    print(head);

    // //insert at head
    // int p;
    // cout<<"No of elements in DL link list to insert at head =>> "<<endl;
    // cin>>p;
    // for (int i = 0; i < p; i++)
    // {
    //     int val;
    //     cout<<"Data "<<i+1<<" ";
    //     cin>>val;
    //     insert_at_head(head,val);
    // } 
    // print(head);

    // //insert at given after val 
    // int x;
    // do
    // {
    //     int val,data;
    //     cout<<"Enter val and data -> "<<endl;
    //     cin>>val>>data;
    //     insert_after_data(head,val,data);
    //     print(head);
    //     cout<<"Enter 0 to exit from insertion "<<endl;
    //     cin>>x;
    // } while (x != 0);

    //deletion of nade  having val
    int k;
    do
    {
        int val;
        cout<<"Deletion of nade  having val -> "<<endl;
        cin>>val;
        deletion_of_node(head,val);
        print(head);
        cout<<"Enter 0 to exit from deletion "<<endl;
        cin>>k;
    } while (k != 0);
    


}