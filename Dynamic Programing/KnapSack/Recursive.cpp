#include <bits/stdc++.h>
int solve(vector<int> weight, vector<int> value,int i,int n, int capacity){
	if(i==n){
		if(weight[i]<=capacity){
			return value[i];
		}
		else{
			return 0;
		}
	}
	int include=0;
	if(weight[i]<=capacity){
		include=value[i]+solve(weight,value,i+1,n,capacity-weight[i]);
	}
	int exclude=solve(weight,value,i+1,n,capacity);

	return max(include,exclude);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	int ans=solve(weight,value,0,n-1,maxWeight);
	return ans;
}