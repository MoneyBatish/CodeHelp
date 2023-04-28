#include <bits/stdc++.h>
int solve(vector<int>&num,int target,vector<int>&dp){
    if(target==0){
        return 1;
    }
    if(target<0){
        return 0;
    }
    if(dp[target]!=-1){
        return dp[target];
    }
    int ans=0;
    for(int i=0;i<num.size();i++){
        ans+=solve(num,target-num[i],dp);
    }

    dp[target]=ans;
    return dp[target];
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    vector<int>dp(tar+1,-1);
    int ans=solve(num,tar,dp);
    return ans;
}