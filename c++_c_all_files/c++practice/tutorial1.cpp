#include <iostream>
#include<string.h>
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int val){
        data=val;
        next=NULL;
    }//constructor
};

void insert_at_begin(node *&head,int val)
{
    node *newnode= new node(val);
    node *ptr=head;
    head=newnode;
    head->next=ptr;
    return;
}

void display(node *head)
{
    node *ptr=head;
    while (ptr!=NULL)
    {
        cout<<ptr->data;
        cout<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL\n";
    return;
}

void insert_at_end(node *&head,int val)
{
    node *ptr=head;
    node *newnode = new node(val);
    if (head==NULL)
    {
        head = newnode;
        return;
    }
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    return;
}

int main()
{
    node *head =NULL;
    int x,n;
    cout<<"Enter the value of x other than -1 if you want to continue your list:\n";
    cin>>x;
    do
    {
        insert_at_end(head,x);
        cout<<"Enter the value of x other than -1 if you want to continue your list:\n";
        cin>>x;
    } while (x!=-1);
    display(head);
    cout<<"Enter the value of x other than -1 if you want to add at start of your list:\n";
    cin>>n;
    do
    {
        insert_at_begin(head,n);
        cout<<"Enter the value of x other than -1 if you want to add at start of your list:\n";
        cin>>n;
    } while (n!=-1);
    display(head);
    
    
    
    
}