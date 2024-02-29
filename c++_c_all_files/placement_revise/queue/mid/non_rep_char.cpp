//check error and correct the code

// string FirstNonRepeating(string A){
//     // Code here
//     queue<int>q;
//     int n = A.length();
//     string ans (n,'#');
//     for(int i= 0; i<n; i++){
//         if(q.empty() ||( A[i] != q.front())){
//             q.push(A[i]);
//             ans[i] = q.front();
//         }
//         else{
//             if(!q.empty() && A[i] == q.front()){
//                 q.pop();
//             }
//         }
//     }
//     return ans;
// }

//approch - 2 -> finding count then use queue to push and pop info

string FirstNonRepeating(string A){
    // Code here
    unordered_map<char,int>count;
    queue<char>q;
    string ans = "";
    
    for(int i=0; i<A.length(); i++){
        
        char ch = A[i];
        // find count of each char
        count[ch]++;
        //push in queue
        q.push(ch);
        
        while(!q.empty()){
            //if we have repeating char then pop
            if(count[q.front()] >1){
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }
        // if we get our queue empty means no elements gets pushed
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}