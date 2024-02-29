#include <bits/stdc++.h> 

//approch 1 ->>>>> Best solution
#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  if(str.length() & 1) return -1;
  int cost = 0;
  stack<char> stack;
  for(char it : str){
    if(it == '{') stack.push(it);
    else{
      if(stack.empty()){
        cost++;
        stack.push('{');
      }
      else{
        stack.pop();
      }
    }
  }
  cost += (stack.size()/2);
  return cost;
}


//approch 2 -> love bubber

#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  // Write your code here
  //odd no of brac
  if(str.length()%2 == 1){
    return -1;
  }
  stack<char>st;
  //even no of brackets
  for(int i=0; i< str.length(); i++){
    char ch = str[i];
    if(ch == '{'){
      st.push(ch);
    }
    else{
      if(!st.empty() && st.top() == '{'){
        st.pop();
      }
      else{
        // we get a closing bracket at start
        st.push(ch);
      }
    }
  }
  //now we have a invalid string of
  // 1. {{{{{{{{{      2. }}}}}}}}}   3.}}}} {{{{  4. }}} {{{
  int c_open = 0;
  int c_close = 0;
  while(!st.empty()){
    char ch1 = st.top();
    if(ch1 == '{'){
      c_open++;
    }
    else{
      c_close++;
    }
    st.pop();
  }
  int ans = (c_close+1)/2 + (c_open+1)/2;
  return ans;
}

