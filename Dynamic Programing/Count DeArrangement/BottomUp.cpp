#define MOD 1000000007
#include<bits/stdc++.h>
long long int countDerangements(int n) {
    // Write your code here.
    vector<long long int>dp(n+1,-1);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++){
        dp[i]=(i-1)*(dp[i-2]+dp[i-1])%MOD;
    }

    return dp[n];

}