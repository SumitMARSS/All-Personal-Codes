//binary search -> O(log(n))
class Solution {
    int left_binary_search(vector<int> nums,int target){
        int start = 0,ans=-1;
        int end = nums.size()-1;
        int mid = start+(end-start)/2;
        while(start <= end){
            if(nums[mid] == target){
                ans = mid;
                end = mid-1;
            }
            if(nums[mid] > target){
                end = mid-1;
            }
            else if(nums[mid] < target){
                start = mid+1;
            }
            mid = start+(end-start)/2;
        }
    return ans;
    }
    int right_binary_search(vector<int> nums,int target){
        int start = 0,ans=-1;
        int end = nums.size() - 1;
        int mid = start+(end-start)/2;
        while(start <= end){
            if(nums[mid] == target){
                ans = mid;
                start = mid+1;
            }
            if(nums[mid] > target){
                end = mid-1;
            }
            else if(nums[mid] < target){
                start = mid+1;
            }
            mid = start+(end-start)/2;
        }
    return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = left_binary_search(nums,target);
        int last = right_binary_search(nums,target);
        return {first,last};
    }
};


//naive approch
vector<int> searchRange(vector<int> &arr, int x)
{
	// Write your code here.
	int ans1=-1, ans2=-1;
	for(int i=0; i<arr.size(); i++){
		if(arr[i] == x && ans1== -1 && ans2 == -1){
			ans1 = i;
			ans2= i;
		}
		if(ans1 != -1 && arr[i] == x){
			ans2 = i;
		}
	}
	return {ans1,ans2};
}

//naive approch - 2

vector<int> searchRange(vector<int> &arr, int x)
{
	// Write your code here.
	int start = -1;
	int end = -1;
	for(int i=0; i<arr.size()-1;i++){
		if(arr[i] == x){
			start = i;
			break;
		}
	}
	for(int i=arr.size(); i>0;i--){
		if(arr[i] == x){
			end = i;
			break;
		}
	}
	return {start,end};
}

 