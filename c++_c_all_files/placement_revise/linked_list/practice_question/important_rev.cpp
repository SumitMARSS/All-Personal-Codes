/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* kReverse(Node* head, int k) {
    // Write your code here.
    //base case
    if(head == NULL){
        return head;
    }
    int n=k;
    //last node will not get reverse
    int count=0;
    Node *temp = head;
    while(temp != NULL){
        count++;
        temp=temp->next;
        
    }
    if(count < k){
        return head;
    }
    //reversal of k node
    Node * prev = NULL;
    Node* curr = head;
    Node *ptr;
    while(curr != NULL && n--){
        ptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ptr;
    }
    //recursion for all rest cases
    Node * rev = kReverse(curr,k);
    head->next = rev;
    return prev;

}