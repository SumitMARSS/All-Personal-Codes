#include<bits/stdc++.h>
using namespace std;

int fiboo(int n, vector<int>&memo_dp){
        //base case
        if( n <= 1 ){
                return n;
        }
        //check if already a value is present
        if(memo_dp[n] != -1){
                return memo_dp[n];
        }
        //store value in dp -> memoization
        memo_dp[n] = fiboo(n-1,memo_dp) + fiboo( n-2 ,memo_dp);
        //return that num
        return memo_dp[n];
}

int main()
{
        int n;
        cin>>n;
        // to store the value of fiboo if once calculated
        //using dp -> recurrsion + memoization ( Top down )
        vector<int> memo_dp(n+1,-1);

        cout<< fiboo(n,memo_dp)<<endl;
        return 0;
}