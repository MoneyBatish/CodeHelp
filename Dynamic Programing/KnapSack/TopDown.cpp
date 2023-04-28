#include <bits/stdc++.h>
int solve(vector<int> weight, vector<int> value,int i,int n, int capacity,vector<vector<int>>&dp){
	if(i==n){
		if(weight[i]<=capacity){
			return value[i];
		}
		else{
			return 0;
		}
	}
	if(dp[i][capacity]!=-1){
		return dp[i][capacity];
	}
	int include=0;
	if(weight[i]<=capacity){
		include=value[i]+solve(weight,value,i+1,n,capacity-weight[i],dp);
	}
	int exclude=solve(weight,value,i+1,n,capacity,dp);

	dp[i][capacity]=max(include,exclude);
	return dp[i][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	int ans=solve(weight,value,0,n-1,maxWeight,dp);
	return ans;
}