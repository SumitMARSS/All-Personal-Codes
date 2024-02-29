//approch - 1 
// time limit exeeds o(n*k)

// vector<long long> printFirstNegativeInteger(long long int A[],
//                                              long long int N, long long int K) {
//         vector<long long>v;
//         for(long long int i=0; i<=N-K; i++){
//             bool flag = false;
//             for(long long int j=i; j <K+i; j++){
//                 if(A[j] < 0){
//                     flag = true;
//                     v.push_back(A[j]);
//                     break;
//                 }
//             }
//             if(!flag){
//                 v.push_back(0);
//             }
//         }
//         return v;
//  }


//approch - 2 doubly ended queue uses

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        deque<long long int>dq;
        vector<long long> ans;
        
        //traverse first window of k element
        for(int i=0; i< K; i++){
            if(A[i] < 0){
                dq.push_back(i);
                //break is not used because we have to push all elements
                //of first window which is less then 0 then check each by 
                //pop_front one by one
            }
        }
        //put in ans
        if(!dq.empty()){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        //rest of loop
        for(int i=K; i<N;i++){
            //pop if in deque out of window index is there
            if(!dq.empty() && (i-dq.front()) >= K){
                dq.pop_front();
            }
            //check for elements having less value
            //addition in queue
            if(A[i] < 0){
                dq.push_back(i);
            }
            //put in ans
            if(!dq.empty()){
                ans.push_back(A[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
 }

//approch- 3 -> check in revision -> same as approch 2 only use of list in place of queue
// vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    
//     long long int i=0;long long int j=0;
//     list<long long int>l;
//     vector <long long int> ans;
//     while(j<N)
//     {
//         if(A[j]<0)
//         {
//             l.push_back(A[j]);
//         }
//         if(j-i+1<K)
//         {
//             j++;
//         }
//         else if(j-i+1==K)
//         {
//             if(l.size()==0)
//             {
//                 ans.push_back(0);
//             }
//             else
//             {
//                 ans.push_back(l.front());
//                 //removing content from list belonging to previous window
//                 if(l.front()==A[i])
//                 {
//                     l.pop_front();
//                 }
//                 //moving the window
//             }
//              i++;
//             j++;    
//         }
//     }
//     return ans;
//  }