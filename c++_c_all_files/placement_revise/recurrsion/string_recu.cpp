#include <bits/stdc++.h>
using namespace std;

//1. reverse a given strings

// //approch 1

// string reverse_string(string &str,int start, int end){
//     cout<<"Reverse call for -> " << str<<endl;
//     //for even element base case is not handled if only == used
//     if (start >= end) 
//     {
//         return str;
//     }
//     swap(str[start],str[end] );
//     return reverse_string(str,start+1,end-1);
// }

// //approch 2 -> optimization

// void reverse(string &str,int start){
// 	if(start >= str.length()-start-1){
// 		return ;
// 	}
// 	swap(str[start],str[str.length()-start-1]);
// 	return reverse(str,start+1);
// }

// int main(){
//     string str = "asumit";
//     int end = str.length()-1;
//     int start = 0;
//     reverse_string(str,start,end);
//     cout<<str<<endl;
// }

//2. check a number is palindrom or not

// //optimization of approch 1
// bool check_pelindrom(string str,int i){
//     if (str.length()-1-i <= i)
//     {
//         return true;
//     }
//     if (str[i] == str[str.length()-1-i])
//     {
//         return check_pelindrom(str,i+1);
//     }
//     return false;
// }

// //approch 1
// bool check_pelindrom_sir(string str,int i,int j){
//     if (j <= i)
//     {
//         return true;
//     }
//     if (str[i] == str[j])
//     {
//         return check_pelindrom_sir(str,i+1,j-1);
//     }
//     return false;
// }

// int main(){
//     string str = "aabbccbbaa";
//     cout<<check_pelindrom(str,0)<<endl;
//     cout<<check_pelindrom_sir(str,0,str.length()-1)<<endl;
// }


//      to check if a number (long long ) is palindrom or not
// bool check_palin(string str,int i){
// 	if(i >= str.length()-(i+1)){
// 		return true;
// 	}
// 	if(str[i] == str[str.length()-(i+1)]){
// 		return check_palin(str,i+1);
// 	}
// 	return false;
// }

// bool checkPalindrome(long long N)
// {
// 	// Write your code here.
// 	string str = to_string(N);
// 	return check_palin(str,0);
// }

// 3. Power of a number

// //optimization of iterative approch
//             // time -complexity - O(log(b))

// int find_power_optimise(int a,int b){
//     if (b==0)
//     {
//         return 1;
//     }
//     if (b%2 ==0)
//     {
//         return find_power_optimise(a,b/2)*find_power_optimise(a,b/2);
//     }
//     else
//     {
//         return a*find_power_optimise(a,b/2)*find_power_optimise(a,b/2);
//     }
// }

// //iterative approch
//             // time -complexity - O(b)
// int find_power(int a,int b){
//     if (b==0)
//     {
//         return 1;
//     }
//     return a*find_power(a,b-1);
// }

// int main(){
//     int a,b;
//     cout<<"Enter a and b ->"<<endl;
//     cin>>a>>b;
//     cout<<"Power of "<<a<<" ^ "<<b<<" -> "<<find_power(a,b)<<endl;
//     cout<<"Power of "<<a<<" ^ "<<b<<" -> "<<find_power_optimise(a,b)<<endl;
// }

//4. Bubble sort

// void sort_arr(int  *(arr),int size){
//     //base case -> check need of size ==0  , i think no need
//     if (size == 1 || size == 0)
//     {
//         return ;
//     }
//     // for one case we solve the problem
//     for (int i = 0; i < size-1; i++)
//     {
//         if (arr[i] > arr[i+1])
//         {
//             swap( arr[i],arr[i+1] );
//         }
//     }
//     // rest recuursion solve
//     return sort_arr(arr,size-1);
// }

// int main(){
//     int arr[] = {5,7,2,6,1,9,3};
//     int size = 7;
//     sort_arr(arr,size);
//     for (int i = 0; i < size; i++)
//     {
//         cout<<arr[i]<<" ";
//     }cout<<endl;
// }