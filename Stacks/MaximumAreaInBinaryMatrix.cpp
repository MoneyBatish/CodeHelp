#include<bits/stdc++.h>
vector<int>nextSmaller(vector<int>&arr,int n)
{
    vector<int>ans(n);
    stack<int>s;
    s.push(-1);
    for(int i=n-1;i>=0;i--)
    {
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int>prevSmaller(vector<int>&arr,int n)
{
    vector<int>ans(n);
    stack<int>s;
    s.push(-1);
    for(int i=0;i<n;i++)
    {
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
int reactangleArea(vector<int> &arr,int n)
{
    vector<int>next;
    next=nextSmaller(arr,n);
    vector<int>prev;
    prev=prevSmaller(arr,n);
    int area=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int length=arr[i];
        if(next[i]==-1)
        {
            next[i]=n;
        }
        int breadth=next[i]-prev[i]-1;
        int newArea=length*breadth;
        area=max(area,newArea);
    }
    return area;
}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	// Write your code here.
    int area=reactangleArea(mat[0],m);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]!=0)
            {
                mat[i][j]=mat[i][j]+mat[i-1][j];
            }
        }
        int newArea=reactangleArea(mat[i],m);
        area=max(area,newArea);
    }
    return area;
}