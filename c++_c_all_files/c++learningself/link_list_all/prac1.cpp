// #include <bits/stdc++.h>
// using namespace std;

// class node{
//     public:
//     int data;
//     node *next ;
//     node(int val){
//         data = val;
//         next = NULL;
//     }
// };

// void print(node *head){
//     node *ptr = head;
//     while (ptr != NULL)
//     {
//         cout<<ptr->data<<"->";
//         ptr = ptr->next;
//     }
// }

// void insert_at_begin(node *&head,int val){
//     node * newnode = new node(val);
//     node *ptr = head;
//     newnode->next = ptr;
//     head = newnode;
// }

// void insert_at_any_point(node *&head, int val, int point){
//     node *ptr = head;
//     node *newnode = new node(val);
//     while (ptr->data != point)
//     {
//         ptr = ptr->next;
//     }
//     newnode->next = ptr->next;
//     ptr->next = newnode;
// }

// void insert_at_end(node *&head,int val){
//     node *&ptr = head;
//     node *newnode = new node(val);
//     if (ptr == NULL)
//     {
//         ptr = newnode;
//         return; //it is important in base case 
//     }
//     while (ptr->next!=NULL)
//     {
//         ptr=ptr->next;
//     }
//     ptr->next = newnode;
//     //return;
// }

// int main(){
//     node *head = NULL;
//     insert_at_end(head,3);
//     insert_at_end(head,6);
//     insert_at_begin(head,1);
//     insert_at_any_point(head,5,3);
//     print(head);
// }


