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

//working properly

void remove_duplicates(node *&head){
    Node *slow = head;
    Node *fast ;
    if(head == NULL){
        return head;
    }
    if(head!=NULL){
        fast = head->next;
    }
    else{
        fast = NULL;
    }
    while (fast !=NULL )
    {
        if (fast!=NULL && slow->data == fast->data)
        {
            Node *todelete = fast;
            slow->next = fast->next;
            fast = slow->next;
            delete todelete;
        }
        else{
            slow = slow->next;
            fast = fast->next;
        }
    }
    return head;
}

//remove dup with no error

// void remove_duplicates(node *&head){
//     if(head == NULL){
//         return NULL;
//     }
//     Node *ptr = head;
//     while(ptr != NULL ){
//         if((ptr->next != NULL) && (ptr->data == ptr->next->data) ){
//             Node *todelete = ptr->next;
//             delete todelete;
//             ptr->next = ptr->next->next;
            
//         }
//         else{
//             ptr = ptr->next;
//         }
//     }
//     return head;
// }



void print(node *ptr){
    while (ptr != NULL)
    {
        cout<< ptr->data <<" -> ";
        ptr = ptr->next;
    }cout<<"NULL"<<endl;
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
    //from sorted
    //remove_duplicates(head);
    //from unsorted
    
    print(head);
}