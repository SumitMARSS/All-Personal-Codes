#include <bits/stdc++.h>
using namespace std;

//circular link list

//class must be similer to singly link list
class node{
    public:
    int data;
    node *next;

    node(int val){
        this->data = val;
        this->next = NULL;
    }
};

void insert_at_head(node *&head, int val){
    node *newnode = new node(val);
    //first case
    if (head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
        return;
    }
    //rest case
    node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    newnode->next = head;
    ptr->next = newnode;
    head = newnode;
} 

void insert_at_end(node *&head, int val){

    node *ptr = head;
    node *newnode = new node(val);
    //first case
    if (head == NULL)
    {
        insert_at_head(head,val);
        return;
    }
    //rest case
    while (ptr->next != head)
    {
        ptr = ptr->next ;
    }
    ptr->next = newnode;
    newnode->next = head;
}

void delete_by_val(node *&head, int val){
    node *ptr = head;
    //for head deletion
    if (head->data == val)
    {
        //delete at head case you can make funct and then write from line 63-70
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        node *todelete = head;
        ptr->next = head->next;
        head = head->next;
        delete todelete;
        return;
    }
    //for rest case
    while (ptr->next->data != val)
    {
        ptr = ptr->next;
    }
    node *todelete = ptr->next;
    ptr->next = ptr->next->next ;
    delete todelete;
}

void print(node *head){
    node *ptr = head;
    do
    {
        cout<<ptr->data<<" -> ";
        ptr=ptr->next;
    } while (ptr != head);  //while (ptr != NULL); just for checking whether a loop is there or not
    cout<<" -> "<<endl;
}

bool detect_cycle(node *head){
    node *ptr = head;
    if (head == NULL)
    {
        return false;
    }
    
    unordered_map <node* , bool > visited;
    while (ptr != NULL)
    {
        if (visited[ptr])
        {
            return true;
        }
        visited[ptr] = true;
        ptr = ptr->next;
    }
    return false;
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
    node *head = NULL;
    int n;
    cout<<"Enter n ->"<<endl;
    cin>>n;   

    //insertion
    for (int i = 0; i < n; i++)
    {
        int val;
        cout<<"Enter val: -> "<<endl;
        cin>>val;
        insert_at_end(head,val);
    }
    print(head);
    insert_at_head(head,100);
    print(head);

    //deletion
    int k;
    do
    {
        int val;
        cout<<"Enter value of node deletion -> "<<endl;
        cin>>val;
        delete_by_val(head,val);
        print(head);
        cout<<"Enter value of k (0 for exit) -> "<<endl;
        cin>>k;
    } while (k!=0);
    //unordered map

    // bool is_cycle = detect_cycle(head); 
    // if (is_cycle)
    // {
    //     cout<<" cycle is present un map "<<endl;
    // }
    // else
    // {
    //     cout<<" cycle is not present un map "<<endl;
    // }

    //ffloyd's circle detection 

    bool is_cycle = detect_cycle_floyd(head); 
    if (is_cycle)
    {
        cout<<" cycle is present floyd "<<endl;
    }
    else
    {
        cout<<" cycle is not present floyd "<<endl;
    }
    
    
    
}