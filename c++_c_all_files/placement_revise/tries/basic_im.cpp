#include<iostream>
using namespace std;

// a tries with 26 splits as 26 alphabets
class trinode{
    public:
    char data;
    trinode* children[26];
    bool isterminal;

    trinode(char val){
        this->data = val;
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        this->isterminal = false;
    }
};

void insert_string(trinode* root, string str){

    //check inserting element 
    //cout<<" inserting -> "<<str<<endl;
    //base case
    if(str.length()  == 0){
        root->isterminal = true;
        return;
    }

    char ch = str[0];
    int index = ch - 'a';
    trinode * next;
    if (root->children[index] == NULL)
    {
        // if not present
        next = new trinode(ch);
        root->children[index] = next;
    }
    else
    {
        //present 
        next = root->children[index];
    }
    //rest case recuursion sambhal lega
    insert_string(next,str.substr(1));
}

bool search_in_tries(trinode* root, string str){

    //base case
    if (str.length() == 0)
    {
        // if(root->isterminal == true){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        return root->isterminal;    //same as line 52-57
    }
    //rest case
    char ch = str[0];
    int index = ch - 'a';
    trinode* child;
    if(root->children[index] != NULL){
        child = root->children[index];
        return search_in_tries(child,str.substr(1));
    }
    else{
        return false;
    }
}

void delete_a_string(trinode* root, string str){
    //base case
    if(str.length() == 0){
        root->isterminal = false;
        return;
    }
    //rest
    char ch = str[0];
    int index= ch - 'a';
    trinode * child;
    if( root->children[index] != NULL){
        child = root->children[index];
        delete_a_string(child,str.substr(1));
    }
    else{
        return;
    }
}

int main(){
    trinode * root = new trinode('-');
    //insertion
    insert_string(root, "sumit");
    insert_string(root, "mini");
    insert_string(root, "asmit");
    insert_string(root, "sumitkuma");
    insert_string(root, "sumitbewk");
    //searching
    cout<<"checking presence -> "<<search_in_tries(root,"mini")<<endl;
    //deletion
    cout<<"checking presence of sumit before deletion -> "<<search_in_tries(root,"sumit")<<endl;
    delete_a_string(root,"sumit");
    cout<<"checking presence of sumit after deletion -> "<<search_in_tries(root,"sumit")<<endl;
}