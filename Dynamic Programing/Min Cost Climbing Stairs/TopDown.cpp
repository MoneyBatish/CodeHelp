int solve(vector<int>&dp,vector<int>& cost,int n){
        if(n==1 || n==0){
            return cost[n];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int c=0;
        if(n!=cost.size()){
            c=cost[n];
        }
        dp[n]= c+min(solve(dp,cost,n-1),solve(dp,cost,n-2));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return solve(dp,cost,n);
    }