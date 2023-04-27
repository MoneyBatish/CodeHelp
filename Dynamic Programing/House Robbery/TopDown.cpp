#include <bits/stdc++.h>
long long int answer(vector<int>&arr,int n,int i,vector<long long int>&dp){
    if(i==n){
        return arr[i];
    }
    if (i > n) {
      return 0;
    }

    if (dp[i] != -1){
        return dp[i];
    }
    long long int inc=answer(arr,n,i+2,dp)+arr[i];
    long long int excl=answer(arr,n,i+1,dp);

    dp[i]=max(inc,excl);
    return dp[i];
}
long long int solve(vector<int>&arr){
    int n=arr.size();
    vector<long long int>dp(n+1,-1);
    long long ans=answer(arr,n-1,0,dp);
    return ans;
} 
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();
    if(n==1){
        return valueInHouse[0];
    }

    vector<int>first,second;
    for(int i=0;i<n;i++){
        if(i!=n-1){
            first.push_back(valueInHouse[i]);
        }

        if(i!=0){
            second.push_back(valueInHouse[i]);
        }
    }

    return max(solve(first),solve(second));
}