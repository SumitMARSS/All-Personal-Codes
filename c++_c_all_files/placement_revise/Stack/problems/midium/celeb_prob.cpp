//brute force
//0(n^2)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        
        // code here 
        int m = M.size();
        for(int i=0; i<m; i++){
            int count=0;
            for(int j=0; j<n; j++){
                if(M[i][j] == 0){
                    count++;
                }
            }
            //celeb don't know anyone a potential candidate
            if(count == n){
                int p=0;
                //checking the column of ith index
                for(int k=0; k<m; k++){
                    if(M[k][i] == 1){
                        p++;
                    }
                }
                //only a condition where diagonal element will be zero
                if(p == m-1){
                    return i; //returning index of celeb
                }
            }
        }
        return -1;
    }
};

//optimization --> O(n)

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>s;
        int i = 0;
        //sare element/person ko dal do satck me
        while(i < n){
            s.push(i++);
        }
        //2 person ko nikalo or check karo
        while(s.size() > 1){
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            
            //x knows y as x can't be celeb
            if(M[x][y] == 1){
                s.push(y);
            } 
            //y knows x as y can't be celeb
            else{
                s.push(x);
            }  
        }
        int p = s.top();    // a potential candidate
        //stack size == 1 means top element is a potential celeb
        //check its row
        int zero_count = 0;
        for(int i=0; i<n; i++){
            if(M[p][i] == 0){
                zero_count++;
            }
        }
        //check its row
        int one_count = 0;
        for(int i=0; i<n; i++){
            if(M[i][p] == 1){
                one_count++;
            }
        }
        
        if(zero_count == n  && one_count == n-1){
            return p;
        }else{
            return -1;
        }
    }

};