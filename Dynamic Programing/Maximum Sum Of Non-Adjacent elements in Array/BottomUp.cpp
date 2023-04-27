#include <bits/stdc++.h>
int solve(vector<int>& arr,int n){
    vector<int>dp(n+1);
    dp[0]=arr[0];

    for(int i=1;i<=n;i++){
        int inc=dp[i-2]+arr[i];
        int excl=dp[i-1];
        dp[i]=max(inc,excl);
    }
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    int ans=solve(nums,n-1);
    return ans;
}