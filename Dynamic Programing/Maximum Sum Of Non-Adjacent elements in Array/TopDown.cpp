#include <bits/stdc++.h>
int solve(vector<int>& arr,int n,vector<int>& dp){
    if(n==0){
        return arr[n];
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int inc=arr[n]+solve(arr,n-2,dp);
    int exc=solve(arr,n-1,dp);
    dp[n]=max(inc,exc);
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n+1,-1);
    int ans=solve(nums,n-1,dp);
    return ans;
}