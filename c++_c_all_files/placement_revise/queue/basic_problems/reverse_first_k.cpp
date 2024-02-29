
//approch - 1 -> stack approch but we need to add extra q1 queue as space

// queue<int> modifyQueue(queue<int> q, int k) {
//     // add code her
//     if ((q.empty() && q.size() == 1) || (k == 0)) {
//         return q;
//     }
//     stack<int>s;
//     while(k--){
//         s.push(q.front());
//         q.pop();
//     }
//     queue<int>q1;
//     while(!s.empty()){
//         q1.push(s.top());
//         s.pop();
//     }
//     while(!q.empty()){
//         q1.push(q.front());
//         q.pop();
//     }
//     return q1;
// }

//approch 2 -> method 2

// queue<int> modifyQueue(queue<int> q, int k) {
//     //no need as we are already returning q
//     // if ((q.empty() && q.size() == 1) || (k == 0)) {
//     //     return q;
//     // }
//     int n = q.size()-k;
//     stack<int>s;
//     // 1 2 3 4 5
//     while(k--){
//         s.push(q.front());
//         q.pop();
//     }
//     //stack -> 3 2 1
//     while(!s.empty()){
//         q.push(s.top());// push in same queue
//         s.pop();
//     }
//     // queue -> 4 5 3 2 1 hence add n-k element -> pop from front and add at end 
//     while(n--){
//         int val = q.front();
//         q.pop();//pop from front
//         q.push(val);
//     }
//     return q;
// }




//approch - 2 -> recursion approch
