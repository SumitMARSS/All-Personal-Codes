//Function to reverse the queue.

//approch - 1 -> stack approch

// class Solution
// {
//     public:
//     queue<int> rev(queue<int> q)
//     {
        // // add code here.
        // if(q.size() == 1){
        //     return q;
        // }
        // stack<int>s;
        // queue<int>q1;
        // while(!q.empty()){
        //     s.push(q.front());
        //     q.pop();
        // }
        // while(!s.empty()){
        //     q1.push(s.top());
        //     s.pop();
        // }
        // return q1;
//     }
// };

//approch - 2 recurssion approch

// class Solution
// {
//     private:
//     void reverse(queue<int> &q){
//         //base case
//         if(q.empty()){
//             return;
//         }
//         //element ko side rakho
//         int element = q.front();
//         q.pop();
//         //reverse rest queue
//         reverse(q);
//         //when we get our queue reversed
//         q.push(element);
//     }
    
//     public:
//     queue<int> rev(queue<int> q)
//     {
//         // add code here.
//         if(q.empty()){
//             return q;
//         }
//         if(q.size() == 1){
//             return q;
//         }
//         reverse(q);
//         return q;
//     }
// };