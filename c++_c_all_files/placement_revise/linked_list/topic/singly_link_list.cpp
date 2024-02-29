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

void insert_at_point(node *&head,int data,int val){
    node *ptr = head;
    node *newnode  = new node(val);
    while (ptr->data != data)
    {
        ptr = ptr->next;
    }
    node* last_address = ptr->next;
    ptr->next = newnode;
    newnode->next = last_address;
}

void insert_after_index(node *&head,int index,int val){
    node *ptr = head;
    node *newnode  = new node(val);
    while (index--)
    {
        ptr = ptr->next;
    }
    node *last_loc = ptr->next;
    ptr->next = newnode;
    newnode->next = last_loc;
}

//deletion
void deletion_of_node(node *&head,int val){
    node *ptr = head;
    node *todelete;
    //if node is empty
    if (ptr == NULL)
    {
        return;
    }
    //if node first element we have to delete
    if (ptr->data == val)
    {
        head = head->next;
        todelete = ptr;
        delete todelete;
        return;
    }
    //for all nodes except first node
    while (ptr->next->data != val)
    {
        ptr = ptr->next;
    }
    todelete = ptr->next;
    ptr->next = todelete->next;
    todelete->next = NULL;
    delete todelete;
}

//recursive approch for reversal of link list
node *reverse_recurr_ll(node *&head){
    //base case
    if (head ==NULL || head->next == NULL)
    {
        return head;
    }
    node* chotahead = reverse_recurr_ll(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotahead;
}

//recursive approch for reversal of link list approch 2
//baed on iterative approch
node * reverse_recurr_ll_approch3(node *head, node *curr, node *prev){
    //base case
    if (curr == NULL)
    {
        return prev;
    }
    node *rev = reverse_recurr_ll_approch3(head, curr->next,curr);
    curr->next = prev;
    return rev;
}

//reverse a link list iterative approch 
node* reverse_link_list(node *&head){
    node *prev = NULL;
    node *curr = head;
    //approch 2
    
    node *ptr ;
    while (curr != NULL)
    {
        ptr = curr->next; 
        curr->next = prev;
        prev = curr;
        curr = ptr;
    }
    return prev;

    //approch - 3
    // node *rev = reverse_recurr_ll_approch3(head,curr,prev);
    // return rev;
    
}

node *reverse_k_node(node *head,int k){
    if (head == NULL )
    {
        return head;
    }
    int m=k;
    node *prev = NULL;
    node *curr = head;
    node *ptr ;
    //reverse k-node
    while (curr !=NULL && m--)
    {
        ptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ptr;
    }
    node *check = curr;
    node *rev = reverse_k_node(curr,k);
//head value or head node didn't change as here from that 
//we track the last location of our node which we have to connect to rest
    head->next = rev;
    
    return prev;
}


void print(node *ptr){
    while (ptr != NULL)
    {
        cout<< ptr->data <<" -> ";
        ptr = ptr->next;
    }cout<<"NULL"<<endl;
}

// bool detect_cycle(node *head){
//     if (head == NULL)
//     {
//         return false;
//     }
//     node *ptr = head;
//     unordered_map <node* , bool > visited;  // space complexity = O(n)
//     while (ptr != NULL)
//     {
//         if (visited[ptr])
//         {
//             return true;
//         }
//         visited[ptr] = true;
//         ptr = ptr->next;
//     }
//     return false;
// }

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
    // int k;
    // cout<<"Enter the no of elements you want in front of link list -> "<<endl;
    // cin>>k;
    // for (int i = 0; i < k; i++)
    // {
    //     int val;
    //     cout<<"Data "<<i+1<<" ";
    //     cin>>val;
    //     insertion_at_head(head,val);
    // }
    // print(head);
    // //insert after value
    // int p;
    // do
    // {
    //     int data,val;
    //     cout<<"Enter data after which you want a node insertion ->";
    //     cin>>data;
    //     cout<<"Enter val of new node insertion ->";
    //     cin>>val;
    //     insert_at_point(head,data,val);
    //     print(head);
    //     cout<<"Enter p (-1 if yu want to exit ):";
    //     cin>>p;
    // } while (p != -1);
    // //index after given index given val
    // insert_after_index(head,5,30);
    // print(head);

    // //deletion 
    // int s;
    // do
    // {
    //     int val;
    //     cout<<"Enter val of node for deletion ->";
    //     cin>>val;
    //     deletion_of_node(head,val);
    //     print(head);
    //     cout<<"Enter s (-1 if yu want to exit ):";
    //     cin>>s;
    // } while (s != -1);

    //reverse a link list
    node *reverse = reverse_link_list(head);
    print(reverse);
    node *rec_rev = reverse_recurr_ll(reverse);
    print(rec_rev);
    print(head);//remains same head
    node *k_ptr = reverse_k_node(head,3);
    print(k_ptr);
    bool is_cycle = detect_cycle_floyd(head); 
    if (is_cycle)
    {
        cout<<" cycle is present "<<endl;
    }
    else
    {
        cout<<" cycle is not present "<<endl;
    }
    
    

}

























// int main(){
//     //dynamic allocation with data

//     // node * head  = new node(10);
//     // cout<< head->data <<endl;
//     // cout<<head->next <<endl;
// }

