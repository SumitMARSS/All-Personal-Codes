#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *next;
    node(int val){
        data=val;
        next=NULL;
    }
};

/*
//if we want to reverse list without having last one
void reverse_list(node *&head)
{
    node *next_ptr;
    node *current=head, *previous=NULL;
    while (current!=NULL)
    {
        next_ptr=current->next;
        current->next=previous;
        previous=current;
        current=next_ptr;
    }
    head=previous;
    return;
}
//without changing the original list
node * reverse_list(node *&head)
{
    node *next_ptr;
    node *current=head, *previous=NULL;
    while (current!=NULL)
    {
        next_ptr=current->next;
        current->next=previous;
        previous=current;
        current=next_ptr;
    }
    return previous;
}*/
node * reverse_recurrsion_list(node *&head)
{
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
     //1->2->3->4->NULL
    node *newnode = reverse_recurrsion_list(head->next);//1->2<-3<-4
    head->next->next=head;//1<-2<-3<-4
    head->next=NULL;//NULL<-1<-2<-3<-4
    return newnode;
}

void delete_at_begin(node *&head)
{
    node  *todelete=head;
    head=head->next;
    cout<<"Your list is deleted...\n";
    delete todelete;
}

void delete_by_value(node *&head,int val)
{
    if (head==NULL)//a case if list is already null
    {
        cout<<"Your list is already empty...\n";
        return;
    }
    if (head->next==NULL)//if only one node is present
    {
        delete_at_begin(head);
    }
    node *ptr=head;
    while ((ptr->next)->data!=val)
    {
        ptr=ptr->next;
    }
    node *deleted_node = ptr->next;
    ptr->next=(ptr->next)->next;
    delete deleted_node;
}

void delete_at_end(node *&head)
{
    node *ptr=head;
    while ((ptr->next)->next!=NULL)
    {
        ptr=ptr->next;
    }
    node *todelete= ptr->next;
    ptr->next=NULL;
    delete todelete;
}

void insert_at_given_point(node *&head, int val)
{
    int n;
    node *ptr=head;
    node *temp;
    cout<<"Enter data to enter\n";
    cin>>n;
    node *newnode = new node(n);
    while (ptr->next!=NULL)
    {
        if (ptr->data==val)
        {
            temp=ptr->next;
            ptr->next=newnode;
            newnode->next=temp;
        }
        ptr=ptr->next;
    }
}

void insert_at_begin(node *&head, int val)
{
    node *newnod= new node(val);
    node *ptr=head;
    head=newnod;
    head->next=ptr;
}

void insert_at_end(node *&head, int val)
{
    node *ptr=head;
    node *newnode = new node(val);
    if (head==NULL)
    {
        head=newnode;
        return;
    }
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    return;
}

void display(node *head)
{
    node *ptr=head;
    while (ptr!=NULL)
    {
        cout<<ptr->data<<"  ";
        ptr=ptr->next;
    }
}

int main()
{
    node *head=NULL;
    node *newhead;
    insert_at_end(head,2);
    insert_at_end(head,3);
    insert_at_end(head,4);
    //display(head);
    insert_at_begin(head,5);
    //delete_at_end(head);
    //delete_at_begin(head);
    //delete_by_value(head,5);
    //insert_at_given_point(head,3);
    display(head);
    cout<<"\n";
    //newhead=reverse_list(head);
    newhead=reverse_recurrsion_list(head);
    display(newhead);
}