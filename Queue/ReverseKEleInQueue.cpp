#include <bits/stdc++.h> 
queue<int> reverseElements(queue<int> q, int k)
{
    // Write your code here.
    stack<int>s;
    for(int i=0;i<k;i++)
    {
        int val=q.front();
        q.pop();
        s.push(val);
    }
    while(!s.empty())
    {
        int val=s.top();
        s.pop();
        q.push(val);
    }
    int t=q.size()-k;
    while(t--)
    {
        int val=q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

/////////////////OR/////////////////

#include <bits/stdc++.h> 
void rev(queue<int>&q,int k,int i=0)
{
    if(i==k)
    {
        return;
    }
    int val=q.front();
    q.pop();
    rev(q,k,i+1);
    q.push(val);
}
queue<int> reverseElements(queue<int> q, int k)
{
    // Write your code here.
    rev(q,k);
    int t=q.size()-k;
    while(t--)
    {
        int val=q.front();
        q.pop();
        q.push(val);
    }
    return q;
}
