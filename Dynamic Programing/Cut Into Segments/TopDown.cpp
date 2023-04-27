#include<bits/stdc++.h>
int solve(int n,int x,int y,int z,vector<int>&dp){
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}
	if(dp[n]!=-1){
		return dp[n];
	}

	int A=solve(n-x,x,y,z,dp)+1;
	int B=solve(n-y,x,y,z,dp)+1;
	int C=solve(n-z,x,y,z,dp)+1;

	dp[n]=max(A,max(B,C));
	return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	vector<int>dp(n+1,-1);
	int ans=solve(n,x,y,z,dp);
	if(ans<0){
		return 0;
	}
	else{
		return ans;
	}
}