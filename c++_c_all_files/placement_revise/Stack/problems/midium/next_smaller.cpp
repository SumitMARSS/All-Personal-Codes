vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here. -> chatgpt
    vector<int> v(n, -1);  // Initialize the result vector with -1

    stack<int> s;  // Stack to store indices of elements

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            v[s.top()] = arr[i];  // Update the result for elements in stack
            s.pop();
        }
        s.push(i);
    }

    return v;



    //approch 2 -> love sir
    vector<int> v(n);
    stack <int> st;
    st.push(-1);
    for(int i=n-1; i>=0; i--){
        while( st.top() >= arr[i]){
            st.pop();
        }
        v[i] = st.top();
        st.push(arr[i]);
    }
    return v;
}