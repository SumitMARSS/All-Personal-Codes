// #include <bits/stdc++.h>
// using namespace std;

// class node{
//     public:
//     int data;
//     node *next;
//     node (int val){
//         data=val;
//         next=NULL;
//     }
// };

// void insert_at_end(node *&head,int val){
//     node *newnode = new node(val);
//     if (head==NULL)
//     {
//         head=newnode;
//         return;
//     }
//     node *ptr=head;
//     while (ptr->next!=NULL)
//     {
//         ptr=ptr->next;
//     }
//     ptr->next=newnode;
//     return;
// }

// void display(node *head){
//     node *ptr=head;
//     while (ptr!=NULL)
//     {
//         cout<<ptr->data<<"->";
//         ptr=ptr->next;
//     }
//     cout<<"NULL\n";
//     return;
// }

// void insert_at_begin(node *&head,int val){
//     node *newnode = new node(val);
//     node *ptr= head;
//     newnode->next= ptr;
//     head = newnode;
// }

// void delete_at_head(node *&head){
//     node *ptr = head;
//     head=head->next;
//     delete ptr;
// }

// void delete_at(node *&head,int val){
//     node *del;
//     if (head==NULL)
//     {
//         cout<<"Your list is empty\n";
//         return;
//     }
//     if (head->next==NULL)
//     {
//         delete_at_head(head);
//         return;
//     }
//     node *ptr= head;
//     while (ptr->next->data!=val)
//     {
//         ptr=ptr->next;
//     }
//     del = ptr->next;
//     ptr->next=ptr->next->next;
//     delete del;
// }

// node *reverse_the_list(node *&head){
//     node *prev = NULL;
//     node *current = head;
//     node *ptr;
//     while (current!=NULL)
//     {
//         ptr=current->next;
//         current->next=prev;
//         prev=current;
//         current=ptr;
//     }
//     return prev;
// }

// node *reverse_recuur_list(node *&head){
//     if (head==NULL || head->next==NULL)
//     {
//         return head;
//     }
//     node *newhead= reverse_recuur_list(head->next);
//     head->next->next=head;
//     head->next=NULL;
//     return newhead;
// }

// int main()
// {
//     node *head=NULL;
//     int n,k,p,d,s,t;
//     cout<<"Enter the no of elements:\n";
//     cin>>n;
//     for (int i = 0; i < n; i++)
//     {
//         cout<<"Enter the value of elements:\n";
//         cin>>k;
//         insert_at_end(head,k);
//         display(head);
//     }
//     cout<<"Enter the value of elements to add at start:\n";
//     cin>>p;
//     insert_at_begin(head,p);
//     display(head);
//     cout<<"Enter the val you want to delete:\n";
//     cin>>d;
//     delete_at(head,d);
//     display(head);
//     cout<<"Enter 1 to reverse the list:\n";
//     cin>>s;
//     if (s==1)
//     {
//         node *revhead= reverse_the_list(head);
//         display(revhead);
//         cout<<"Enter 1 to reverse the list by recuursion:\n";
//         cin>>t;
//         if (t==1)
//         {
//             node *reccurhead= reverse_recuur_list(revhead);
//             display(reccurhead);
//         }
//     }
    
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void at_begin(node *&head, int val){
    node *newnode = new node (val);
    node *ptr = head;
    newnode->next = ptr;
    head = newnode;
    return;
}

void add_at_end(node *&head,int val){
    node *newnode = new node(val);
    if (head==NULL)
    {
        head = newnode;
        return;
    }
    node *ptr=head;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    return;
}

void display(node *head){
    node *ptr= head;
    while (ptr!=NULL)
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL\n";
    return;
}

void del_at_head(node *&head){
    node *ptr = head;
    head = head->next;
    delete ptr;
}

void del_at_anypoint(node *&head, int delval){
    if (head==NULL)
    {
        cout<<"Your list is empty\n";
        return;
    }
    if (head->next==NULL)
    {
        del_at_head(head);
    }
    node *ptr = head;
    node *delnode;
    while (ptr->next->data!=delval)
    {
        ptr=ptr->next;
    }
    delnode = ptr->next;
    ptr->next=ptr->next->next;
    delete delnode;
}

node *reverse_the_list(node *&head){
    node *current = head;
    node *prev = NULL;
    node *ptr;
    while (current!=NULL)
    {
        ptr = current->next;
        current->next = prev;
        prev = current;
        current = ptr;
    }
    return prev;
}

node *recurr_reverse_the_list(node *&newhead){
    if (newhead==NULL || newhead->next==NULL)
    {
        return newhead;
    }
    node *recurr_head = recurr_reverse_the_list(newhead->next);
    newhead->next->next = newhead;
    newhead->next = NULL;
    return recurr_head;
}

node *reverse_k_regular_nodes(node *&head , int k){
    node *prev = NULL;
    node *current = head;
    node *ptr;
    int count = 0;
    while (current!=NULL && count<k)
    {
        ptr = current->next;
        current->next= prev;
        prev = current;
        current = ptr;
        count++;
    }
    if (ptr!=NULL)
    {
        head->next = reverse_k_regular_nodes(ptr,k);
    }
    return prev;
}

void makecycle(node *&reghead,int pos){
    node *ptr = reghead;
    node *startcycle;
    int count=0;
    while (ptr->next!=NULL)
    {
        if (count==pos)
        {
            startcycle = ptr->next;
        }
        ptr=ptr->next;
        count++;
    }
    ptr->next=startcycle;
}

bool detect_cycle(node *&reghead){
    node *fast = reghead;
    node *slow = reghead;
    while (fast!=NULL && fast->next!=NULL)
    {
        fast= fast->next->next;
        slow=slow->next;
        if (slow==fast)
        {
            return true;
        }
    }
    return false;
}

void make_uncycle(node *&reghead){
    node *fast = reghead;
    node *slow = reghead;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);
    fast = reghead;
    while (slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

int main(){
    node *head = NULL;
    node *newhead = NULL;
    node *rehead = NULL;
    node *reghead = NULL;
    int n,val,val1,delval,k,p;
    cout<<"Enter the number of elemenets you want to enter\n";
    cin>>n;
    while (n--)
    {
        cout<<"Enter the val\n";
        cin>>val;
        add_at_end(head,val);
    }
    display(head);
    cout<<"\nEnter the val at begin addition\n";
    cin>>val1;
    at_begin(head,val1);
    display(head);
    cout<<"\nEnter the delval\n";
    cin>>delval;
    del_at_anypoint(head,delval);
    display(head);
    newhead=reverse_the_list(head);
    display(newhead);
    rehead= recurr_reverse_the_list(newhead);
    display(rehead);
    cout<<"Enter the value of k\n";
    cin>>k;
    display(head);
    reghead= reverse_k_regular_nodes(head,k);
    display(reghead);
    cout<<"Enter the val\n";
    cin>>p;
    makecycle(reghead,p);
    //display(reghead);
    cout<<"\n\n";
    cout<<detect_cycle(reghead)<<endl;
    make_uncycle(reghead);
    cout<<detect_cycle(reghead)<<endl;
    display(reghead);
}