#include <bits/stdc++.h>
using namespace std;

//1. Subset problem

// void solve(vector<int>& nums,vector<int> output,int index,vector<vector<int>>& ans){
//         //base case 
//         if(index >= nums.size()){
//             ans.push_back(output);
//             return;
//         }
//         //exclude
//         solve(nums,output,index+1,ans);
//         //include
//         int element = nums[index];
//         output.push_back(element);
//         solve(nums,output,index+1,ans);
// }

// //comment lines for similer elements in an array
// vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> output;
//         // sort(nums.begin(),nums.end());
//         int index=0;
//         solve(nums,output,index,ans);
//         // sort(ans.begin(), ans.end());
//         // ans.erase(unique(ans.begin(), ans.end()), ans.end());
//         return ans;
// }

// void print(vector <int> element){
//     for (int i = 0; i < element.size(); i++)
//     {
//         cout<<element[i]<<" ";
//     }cout<<endl;
    
// }

// int main(){
//     vector<int>  arr = {1,2,2,1};
//     vector<vector<int>> ans = subsetsWithDup(arr);
//     for (int  i = 0; i < ans.size(); i++)
//     {
//         print(ans[i]);
//     }cout<<endl;
// }


//2. Subsequence problem

void solve(string str,int index,string out_str,vector<string> &v_str){
	if(index >= str.length()){
        //approch 2 -> removing starting space 55-58
        if (out_str.length()>0)
        {
            v_str.push_back(out_str);
        }
		//v_str.push_back(out_str);
		return;
	}
	//exclusion
	solve(str,index+1,out_str,v_str);
	//inclusion
	char ch = str[index];
	out_str.push_back(ch);
	solve(str,index+1,out_str,v_str);
}

vector<string> subsequences(string str){
	
	// Write your code here
	vector <string> v_str;
	string out_str;
	int index=0;
	solve(str,index,out_str,v_str);
    //approch 1 to remove the space which is at starting
	//v_str.erase(v_str.begin());
	return v_str;
}

void print_str(string element){
    cout<<element<<" ";
}

int main(){
    string str = "abc";
    cout<<"Given string is:  "<<str<<endl;
    vector<string> ans = subsequences(str);
    //just to look good no need
    //sort(ans.begin(),ans.end());

    cout<<"Given string subsequences is:  "<<endl;
    for (int  i = 0; i < ans.size(); i++)
    {
        print_str(ans[i]);
    }cout<<endl;
}
