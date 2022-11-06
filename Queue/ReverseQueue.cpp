#include <bits/stdc++.h> 
queue<int> reverseQueue(queue<int> q)
{
    // Write your code here.
    stack<int>s;
    while(!q.empty())
    {
        int ele=q.front();
        q.pop();
        s.push(ele);
    }
    while(!s.empty())
    {
        int ele=s.top();
        s.pop();
        q.push(ele);
    }
    return q;
}
//////////////////////OR///////////////////////
            RECURSIVE APPROACH
#include <bits/stdc++.h>

void recq(queue <int>& q){
   if(q.empty())
       return;
   int front = q.front();
   q.pop();
   recq(q);
   q.push(front);
}

queue<int> reverseQueue(queue<int> q)
{
   // Write your code here.
   recq(q);
   return q;
}
