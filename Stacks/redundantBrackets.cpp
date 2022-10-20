#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char>temp;
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/')
        {
            temp.push(ch);
        }
        else{
            if(ch==')'){
                bool redundant=true;
                while(temp.top()!='(')
                {
                    char top=temp.top();
                    if(top=='+' || top=='-' || top=='*' || top=='/')
                    {
                        redundant=false;
                    }
                    temp.pop();
                }
                temp.pop();
                if(redundant==true)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
