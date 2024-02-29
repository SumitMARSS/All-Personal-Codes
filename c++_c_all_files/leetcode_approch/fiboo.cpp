class Solution {
public:
    int fib(int n) {

        // recursive approch
        // time complex = O(2^n), space = O(n)
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        return fib(n-1)+fib(n-2);

        // dynamic approch
        // time complex = O(n), space = O(n)
        if(n<2){
            return n;
        }
        int arr[n+1];//indexing starts from 0
        arr[0]=0;
        arr[1]=1;
        for(int i=2; i<=n; i++){
            arr[i] = arr[i-1]+arr[i-2];
        }
        return arr[n];

        //Imerative approch
        //time complex = O(n)  space = O(1)
        int a = 0;
        int b = 1;
        int c,temt;
        if(n<2){
            return n;
        }
        for(int i=2; i<=n; i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};