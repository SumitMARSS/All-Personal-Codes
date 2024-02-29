bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char>stac;
    
    for(int i=0; i<s.length(); i++){
        //push if we get opening bracket
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            stac.push(s[i]);
        }
        //check and pop if we get closing bracket
        else{
            //closing bracket
            if(!stac.empty()){
                //if matches found then pop
                if  ( 
                    (stac.top() == '('  && s[i] == ')') ||
                    (stac.top() == '{'  && s[i] == '}') ||
                    (stac.top() == '['  && s[i] == ']') 
                    )
                    {
                    stac.pop();
                }
            }else{
                return false;
            }
        }
    }
    if(stac.empty()){
        return true;
    }else{
        return false;
    }
}