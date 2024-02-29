#include <bits/stdc++.h> 

//approch 1 = stack create and push all elelemnt until vacent again pop and push into old stack approch

// stack<int> pushAtBottom(stack<int>& myStack, int x) 
// {
//     // Write your code here.
//     stack<int>newstack;
//     while(!myStack.empty()){
//         newstack.push(myStack.top());
//         myStack.pop();
//     }
//     myStack.push(x);
//     while(!newstack.empty()){
//         myStack.push(newstack.top());
//         newstack.pop();
//     }
//     return myStack;
// }


//approch 2 = recursive approch

// void solve(stack<int> &myStack, int x,int count,int size){
//     //base case
//     if(count == size){
//         myStack.push(x);
//         return ;
//     }
//     //1 element ko pop karke side me rakho
//     int num = myStack.top();
//     myStack.pop();
//     //call recursive
//     solve(myStack,x,count+1,size);
//     //when we get end add these poped element to get full stack
//     myStack.push(num);
// }

// stack<int> pushAtBottom(stack<int>& myStack, int x) 
// {
//     // Write your code here.
//     //recurssive approch
//     int count = 0;
//     int size = myStack.size();
//     solve(myStack,x,count,size);
//     return myStack;
// }


//reverse a stack using recursion

void insert_at_end_stack(stack<int> &stack, int num){
    if(stack.empty()){
        stack.push(num);
        return;
    }
    //side me element ko rakho
    int k = stack.top();
    stack.pop();
    //recursive call for rest element until we get empty stack
    insert_at_end_stack(stack,num);
    //add that element which we poped
    stack.push(k);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    //base case
    if(stack.empty()){
        return;
    }
    //what did recursion says - tum ek case banao baki mai dekh luga
    int num = stack.top();
    stack.pop();
    //let's suppose reversion reverse rest of stack except ist one
    reverseStack(stack);
    //Now w eget our reversed stack so insert our element at the end of stack
    insert_at_end_stack(stack,num);
    
}

//sort a stack

#include <bits/stdc++.h> 


void place_element_in_sorted(stack<int> &stack, int x){
	
	//stack top element agar chota hai ya stack empty ho gaya hai to push x
	if( stack.empty() || (x > stack.top() && !stack.empty())){
		stack.push(x);
		return;
	}
	//agar element x chota hai to stack ke top ko side me rakho
	int num = stack.top();
	stack.pop();
	//recursion for all other case
	place_element_in_sorted(stack,x);

	//return hote samay element ko rakh lo
	stack.push(num);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()){
		return;
	}
	//side me element ko rakho
	int num = stack.top();
	stack.pop();

	//sortStack -> rest all stack will be sorted
	sortStack(stack);
	//case we have to solve
	place_element_in_sorted(stack,num);

}