#include <iostream>
#include <stack>
#include <queue>
using namespace std;
    //Lifo - Last in first out
// int main(){
//     stack <string> s;
//     s.push("Prakash");
//     s.push("Vinay");
//     s.push("chutiya");
//     cout<<"Stack top elements: "<<s.top()<<endl;
//     s.pop();
//     cout<<"Stack top elements: "<<s.top()<<endl;
//     s.pop();
//     cout<<"Stack top elements: "<<s.top()<<endl;
//     s.pop();
//     cout<<"Stack is empty or not: "<<s.empty()<<endl;
//     cout<<"size of stack: "<<s.size()<<endl;

// }

int main(){
    //FIFO - First in First out
    queue <string> s;
    s.push("Prakash");
    s.push("Vinay");
    s.push("chutiya");
    cout<<"queue top elements: "<<s.front()<<endl;
    s.pop();
    cout<<"queue top elements: "<<s.front()<<endl;
    s.pop();
    cout<<"queue top elements: "<<s.front()<<endl;
    s.pop();
    cout<<"queue is empty or not: "<<s.empty()<<endl;
    cout<<"size of queue: "<<s.size()<<endl;

}