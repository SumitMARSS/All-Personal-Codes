//brute force 

//approch 1 -> O(n)

class Solution {

    vector<int>nextSmallerElement(vector<int> arr,int n){
        stack<int>s;
        s.push(-1);
        vector<int> v(n);
        for(int i=n-1; i>=0; i--){
            while(s.top() != -1  && arr[s.top()] >= arr[i]){
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }

    vector<int>prevSmallerElement(vector<int> arr,int n){
        stack<int>s;
        s.push(-1);
        vector<int>v(n);
        for(int i=0; i<n ; i++){
            while(s.top() != -1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>next(n); // store thr next index
        next = nextSmallerElement(heights,n);
        vector<int>prev(n); // store thr prev index
        prev = prevSmallerElement(heights,n);

        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int a = heights[i];
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newarea = a*b;
            area = max( area,newarea);
        }
        return area;
    }
};





class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            
            int area = 0;
            height.push_back(0);
            vector<int> index;
            
            for(int i = 0; i < height.size(); i++)
            {
                while(index.size() > 0 && height[index.back()] >= height[i])
                {
                    int h = height[index.back()];
                    index.pop_back();
                    
                    int sidx = index.size() > 0 ? index.back() : -1;
                    int newarea = h * (i-sidx-1);
                    area = max(area,newarea);
                }
                index.push_back(i);
            }
            
            return area;
        }
    };