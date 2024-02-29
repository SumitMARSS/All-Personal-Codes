#include <bits/stdc++.h>
using namespace std;

// O(nsqrt(n))  time complexity

bool isprime(int n){
    if(n ==0 || n==1){
        return false;
    }
    for(int i=2;i<= sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
int countPrimes(int n) {
    int count = 0;
    
    for(int i=0; i<n; i++){
        if(isprime(i)){
            count++;
        }
    }
    return count;
}

// Sieve of eratosthensis (checking for prime number)

int countPrimes1(int n) {
        int count = 0;
        vector <bool> isprime (n+1,true);
        isprime[0] = isprime[1] = 0;
        for(int i=2; i<n; i++){
            if(isprime[i]){
                count++;
                for(int j=2*i; j<n ; j=j+i){
                    isprime[j]=0;
                }
            }
        }
    return count;
}
int main(){
    int n;
    cout<<"Enter the numbers: "<<endl;
    cin>>n;
    cout<<"Sieve of eratosthensis \n Time complexity -(O(n)^2)) -> "<<countPrimes(n)<<endl;
    cout<<"Sieve of eratosthensis \n Time complexity -(O(log(log(n)))) -> "<<countPrimes1(n)<<endl;
}