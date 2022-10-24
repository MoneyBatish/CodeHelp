#include<stack>
class SpecialStack {
    // Define the data members.

    /*----------------- Public Functions of SpecialStack -----------------*/
    stack<int>s;
    int mini;
    public:
        
    void push(int data) {
        // Implement the push() function.
        
        if(s.empty())
        {
            s.push(data);
            mini=data;
        }
        else{
            if(data<mini)
            {
                s.push(2*data-mini);
                mini=data;
            }
            else{
                s.push(data);
            }
        }
        
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty())
        {
            return -1;
        }
        int curr=s.top();
        s.pop();
        if(curr<mini)
        {
            int prevMini=mini;
            int val=2*mini-curr;
            mini=val;
            return prevMini;
        }
        else{
            return curr;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty()){
            return -1;
        }
        
        int curr=s.top();
        if(curr>mini)
        {
            return curr;
        }
        else{
            return mini;
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return s.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty())
        {
            return -1;
        }
        else{
            return mini;
        }
    }  
};