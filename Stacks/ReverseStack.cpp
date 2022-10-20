void pushAtBottom(stack<int>& s, int x) 
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    pushAtBottom(s,x);
    s.push(num);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    //Base Case
    if(stack.empty()){
        return;
    }
    //Recursion Call
    int elm = stack.top();
    stack.pop();
    reverseStack(stack);
    
    //Push At Bottom
    pushAtBottom(stack,elm);
}