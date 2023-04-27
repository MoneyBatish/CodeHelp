#include<bits/stdc++.h>
int solve(int n,int x,int y,int z){
	vector<int>dp(n+1,-1);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		int A=-1,B=-1,C=-1;
		if(i-x>=0 && dp[i-x]!=-1)
			A=dp[i-x]+1;
		
		if(i-y>=0 && dp[i-y]!=-1)
			B=dp[i-y]+1;
		
		if(i-z>=0 && dp[i-z]!=-1)
			C=dp[i-z]+1;

		dp[i]=max(A,max(B,C));
	}
	if(dp[n]==-1){
		return 0;
	}
	else{
		return dp[n];
	}
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	return solve(n,x,y,z);
}