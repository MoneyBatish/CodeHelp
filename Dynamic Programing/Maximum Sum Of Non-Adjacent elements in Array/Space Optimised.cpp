#include <bits/stdc++.h>
int solve(vector<int>& arr,int n){
    int prev1=arr[0];
    int prev2=0;
    for(int i=1;i<=n;i++){
        int inc=prev2+arr[i];
        int excl=prev1;
        int ans=max(inc,excl);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    int ans=solve(nums,n-1);
    return ans;
}