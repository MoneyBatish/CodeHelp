#include<bits/stdc++.h>
using namespace std;
int fun(int n,vector<int>&dp){
        if(n==1 || n==0){
                return n;
        }
        if(dp[n]!=-1){
                return dp[n];
        }

        dp[n]=fun(n-2,dp)+fun(n-1,dp);
        return dp[n];
}
int main()
{
        int n;
        cin>>n;
        vector<int>dp(n+1,-1);
        int ans=fun(n,dp);
        cout<<ans;
}