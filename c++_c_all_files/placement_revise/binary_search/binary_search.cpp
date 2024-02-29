// #include <bits/stdc++.h>
// using namespace std;


// // time complexity - O(log(n))
// int binary_search(int arr[], int size, int key){
//     int start = 0;
//     int end = size -1;
//     int mid = start+ (end - start)/2;
    
//     while (start<= end)
//     {
//         if (arr[mid] == key)
//         {
//             return mid;
//         }
//         if ( key < arr[mid] )
//         {
//             end = mid-1;
//         }
//         else
//         {
//             start = mid +1;
//         }
//         mid = start + (end - start)/2;
//     }
//     return -1;
// }

// int main(){

//     int even[6] = {2,3,5,6,12,16};
//     int odd[7] = {22,23,35,66,142,176,234};
//     int key1 = 3;
//     cout<<binary_search(even,6,key1)<<endl;
//     int key2 = 234;
//     int index = binary_search(odd,7,key2);

//     cout<<index<<endl;
// }

// question -2 (no of occurance)






//question - 1   (first and last occurance ) 
// pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
// {
//     int first = -1;
//     int last = -1;
//     //second approch  time complex => O(n)
//     for(int i=0; i<n;i++){
//         if(arr[i]==k){
//             if(first==-1){
//                 first = i;
//                 last = i;
//             }
//             else{
//                 last = i;
//             }
//         }
//     }
//     return {first,last};
// }


//question - 1   (first and last ) optimization time- complexity - log(n)


//question -2 no of occurance 
// initial order is asending or decending so total no of occurance:-> [(last occur - first occur)+1]

// #include <bits/stdc++.h> 
// using namespace std;
// int firstocuur(vector<int>& arr, int n, int k){
//     int s=0,e=n-1;
//     int mid = s+(e-s)/2;
//     int ans = -1;
//     while(s<=e){
//         if(arr[mid]==k){
//             ans = mid;
//             e = mid -1;
//         }
//         else if(k > arr[mid]){
//             s = mid+1;
//         }
//         else {
//             e = mid-1;
//         }
//         mid = s+(e-s)/2;
//     }
//     return ans;
// }

// int lastocuur(vector<int>& arr, int n, int k){
//     int s=0,e=n-1;
//     int mid = s+(e-s)/2;
//     int ans = -1;
//     while(s<=e){
//         if(arr[mid]==k){
//             ans = mid;
//             s = mid +1;
//         }
//         else if(k > arr[mid]){
//             s = mid+1;
//         }
//         else {
//             e = mid-1;
//         }
//         mid = s+(e-s)/2;
//     }
//     return ans;
// }
// pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
// {
//     // Write your code here
//     int first = firstocuur(arr,n,k);
//     int last = lastocuur(arr,n,k);
//     cout<<"No of occurance: -> "<< (last - first)+1 <<endl;
//     return {first,last};
// }

// int main(){
//     vector<int>arr ;
//     int n;
//     cout<<"No of element -> "<<endl;
//     cin>>n;
//     for (int i = 0; i < n; i++)
//     {
//         int element;
//         cout<<"a "<<i<<endl;
//         cin>>element;
//         arr.push_back(element);
//     }
//     int key;
//     cout<<"key -> "<<endl;
//     cin>>key;
//     pair<int,int> ans = firstAndLastPosition(arr,arr.size(),key);
//     cout<<ans.first<<" "<<ans.second<<endl;
    
// }


//ques - 3 //finding pivot element (pivot element is max or min element in an array)

// #include <bits/stdc++.h>
// using namespace std;

// int pivot_element(vector <int> &arr){
//     int start = 0;
//     int end = arr.size() - 1;
//     int mid = start + (end - start)/2;
//     while (start<end)
//     {
//         if ( arr[mid] >= arr[0])
//         {
//             start = mid+1;
//         }
//         else
//         {
//             end = mid;
//         }
//         mid = start + (end - start)/2;
//     }
//     cout<<"Pivot index is: -> "<<end<<endl;  //you can take any one as both points are same
//     return arr[start];
// }

// int main(){
//     vector<int>arr ;
//     int n;
//     cout<<"No of element -> "<<endl;
//     cin>>n;
//     for (int i = 0; i < n; i++)
//     {
//         int element;
//         cout<<"a"<<i<<" ";
//         cin>>element;
//         arr.push_back(element);
//     }
//     int p_element=pivot_element(arr);
//     cout<<"Pivot element: ->"<<p_element<<endl;

// }

// 4. search in n-rotated array

int pivot_element(vector<int>& arr){
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end - start)/2;
    while(start < end){
        if(arr[mid]>= arr[0]){
            start = mid+1;
        }
        else{
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return end;
}

int binary_search(vector<int>& arr,int start,int end, int k){
    int mid = start + (end - start)/2;
    while(start <= end){
        if(arr[mid]==k){
            return mid;
        }
        else if(k >arr[mid] ){
            start = mid+1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int pivot = pivot_element(arr);
    if(k >= arr[pivot]  && k <= arr[n-1]){
        return binary_search(arr,pivot,n-1,k);
    }
    else{
        return binary_search(arr,0,pivot-1,k);
    }
    return -1;
}


//5. Square root of n using binary search


// #include <bits/stdc++.h>
// using namespace std;

// int sqr_binary_search(int n){
//     int start = 0;
//     int end = n;
//     long long int mid = start + (end - start)/2;
//     int ans = -1;
//     while(start<=end){
//         long long int square = mid*mid;
//         if(square == n){
//             return mid;
//         }
//         else if(square < n){
            
//             ans = mid;
//             start = mid+1;
//         }
//         else{
//             end = mid -1;
//         }
//         mid = start + (end - start)/2;
//     }
//     return ans;
// }

// double morePrecision(int n,int precision,int ans){
//     double factor = 1;
//     double sol = ans;
//     for (int i = 0; i < precision; i++)
//     {
//         factor = factor/10;
//         for (double j = ans; j*j < n; j=j+factor)
//         {
//             sol = j;
//         }
//     }
//     return sol;
// }

// int main(){
//     int n;
//     cout<<"Enter the no "<<endl;
//     cin>>n;
//     int ans = sqr_binary_search(n);
//     cout<<morePrecision(n,3,ans)<<endl;

// }



//6. Book allocATION problems (Binary Search Problem)

// #include <bits/stdc++.h>
// using namespace std;

// bool isPossible(vector <int> arr, int n, int m, int mid){
//     int page_sum = 0;
//     int student_count =1;
//     for (int i = 0; i < n; i++)
//     {
//         //page_sum + arr[i] means previous pages _ now if pages are added, it can be possible or not
//         if (page_sum+ arr[i] <= mid) 
//         {
//             page_sum += arr[i];
//         }
//         else
//         {
//             student_count++;
//             //find the statement for which we gets false return 
//             if(student_count > m || arr[i] >  mid){ //arr[i]->value if greater then mid return false
//                 return false;
//             }
//             else
//             {
//                 page_sum = arr[i];
//             }
//         }
//     }
//     return true;
// }

// int allocate_book(vector <int> arr,int n,int m){
//     int start = 0,sum=0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//     }
//     int end = sum; //search space must be in between start - end
//     int mid = start + (end-start)/2 ; 
//     int ans=0;
//     while (start <= end)
//     {
//         if (isPossible(arr,n,m,mid))
//         {
//             ans = mid;
//             end = mid-1;
//         }
//         else
//         {
//             start = mid+1;
//         }
//         mid = start + (end-start)/2 ; 
//     }
//     return ans;
// }

// int main(){
//     int n,m;
//     cout<<"Enter the number of books"<<endl;
//     cin>>n;
//     cout<<"No of students "<<endl;
//     cin>>m;
//     vector <int> arr = {10,20,30,40}; //page of ith book
//     int ans = allocate_book(arr,n,m);
//     cout<<ans<<endl;
// }


// // copy of book allocation problems
// #include <bits/stdc++.h> 

// bool isPossible(vector<int>time,long long int n,long long int m,long long int mid){
// 	long long int total_time = 0;
// 	long long int day_num = 1;
// 	for(int i=0; i<m; i++){
// 		if(total_time + time[i] <= mid){
// 			total_time+= time[i];
// 		}
// 		else{
// 			day_num++;
// 			if(day_num > n ||  time[i] > mid){
// 				return false;
// 			}
// 			total_time = time[i];
// 		}
// 	}
// 	return true;
// }

// long long ayushGivesNinjatest(int n, int m, vector<int> time) 
// {	
// 	// Write your code here.
// 	//n-> no of days, m-> chapters
// 	long long int start = 0;
// 	long long int sum_time = 0;
// 	for(int i=0; i<m; i++){
// 		sum_time += time[i];
// 	}
// 	long long int end = sum_time;
// 	//solution space must lie in-between start-end
// 	long long int ans = 0;
// 	long long int mid = start + (end-start)/2;
// 	while(start<=end){
// 		if(isPossible(time,n,m,mid)){
// 			ans = mid;
// 			end = mid-1;
// 		}
// 		else{
// 			start = mid+1;
// 		}
// 		mid = start + (end-start)/2;
// 	}
// 	return ans;
// }

//7. aggressive cow problem

// bool isPosssible(vector<int> &stalls, int k,int mid){
//     int Cow_count = 1;
//     int last_post = stalls[0];
//     for(int i=0; i<stalls.size(); i++){
//         if((stalls[i]-last_post) >= mid){
//             Cow_count++;
//             if(Cow_count ==k){
//                 return true;
//             }
//             last_post = stalls[i];
//         }
//     }
//     return false;
// }

// int aggressiveCows(vector<int> &stalls, int k)
// {
//     //    Write your code here.
//     sort(stalls.begin(),stalls.end());
//     // int start = 0;
//     // int max_stall=0,min_stall=0;
//     // for(int i=0; i< stalls.size(); i++){
//     //     min_stall = min(stalls[i],min_stall);
//     //     max_stall = max(max_stall,stalls[i]);
//     // }
//     //int end = max_stall - min_stall; //max distance

//     // no need of finding min or max if it is already sorted
//     int start = 0;
//     int end = stalls[stalls.size() - 1];// here we have search space
    
//     int mid = start + (end-start)/2;
//     int ans = 0;
//     while(start <= end){
//         if(isPosssible(stalls,k,mid)){
//             ans = mid;
//             start = mid+1;
//         }
//         else{
//             end = mid-1;
//         }
//         mid = start + (end-start)/2;
//     }
//     return ans;
// }