#include <iostream>
#include <stack>
using namespace std;



//Approch 1
//using 2 stack delete middle node
void deleteMiddle(stack<int>&inputStack, int N){
   int mid = N/2+1;
   stack<int>st;
   int i=0;
   while(mid--){
      st.push(inputStack.top());
      inputStack.pop();
   }
   st.pop();
   while(!st.empty()){
      inputStack.push(st.top());
      st.pop();
   }
}

//approch 2 - > recursive approch

void solve(stack<int>&inputStack, int count,int size){
   //base case
   if(count == (size/2)){
      inputStack.pop();
      return;
   }
   //side me element ko rakho
   int num = inputStack.top();
   //poping of that element
   inputStack.pop();
   //recursive call
   solve(inputStack,count+1,size);
   //when recursive call complete push the element which was poped
   inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count = 0;
   solve(inputStack,count,N);
}



//reverse a string -> space complexity - (O(n)) and time complexity - (O(n)) 
string reverse_by_stack(string str){
    stack <char> s;
    int i=0;
    int n=str.length();
    while (n--)
    {
        s.push(str[i++]);
    }
    i=0;
    n=str.length();
    while (!s.empty())
    {
        str[i++] = s.top();
        s.pop();
    }
    return str;
}

int main(){
    
    string str;
    cin>>str;
    cout<<"Your given string is: -> "<<str<<endl;
    cout<<"Your reverse string is: -> "<<reverse_by_stack(str)<<endl;
}