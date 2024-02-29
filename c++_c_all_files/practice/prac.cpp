#include<iostream>
using namespace std;

//count no of 1's in n like 3 -> 11 so count_set = 2
int count_set(int n){
    int count=0;
    while(n){
        n &= (n-1);
        count++;
    }
    return count;
}

// int ceilLog2(int x)
// {
//     int count = 0;
//     x--;
//     while (x > 0) {
//         x = x >> 1;
//         count++;
//     }
//     return count;
// }

int find_new_num(int n){
    if( n > 31){
        return n-31;
    }
    return 1;
}

int is_bleak(int n)
{
    // for(int i= n - ceilLog2(n) ; i<n; i++){
    //     if( i + count_set(i) == n ){
    //         return false;
    //     }
    // }
    
    // find count_set directly formula
    //cout<<__builtin_popcount(3)<<endl;
    
    int s = find_new_num(n);
    
    for(int i= s ; i<n; i++){
        if( i + count_set(i) == n ){
            return false;
        }
    }
    return true;
}

int main(){
    int n; 
    cout<<"Enter the number "<<endl;
    cin >> n;
    int ans = is_bleak(n);
    cout << " Given no is bleak or not  --> " << ans << "\n";
	return 0;
}