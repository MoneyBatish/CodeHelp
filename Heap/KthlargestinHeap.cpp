#include <bits/stdc++.h> 
int kthLargest(vector<int>& nums, int size, int k)
{
	// Write your code here.
    priority_queue<int,vector<int>,greater<int>>MIN;
     for(int i=0;i<k;i++)
     {
         MIN.push(nums[i]);
     }
     for(int i=k;i<size;i++)
     {
         if(nums[i]>MIN.top())
         {
             MIN.pop();
             MIN.push(nums[i]);
         }
     }
     
     return MIN.top();
}