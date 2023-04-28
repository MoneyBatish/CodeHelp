int solve(int arr[],int n,int curr,int prev,vector<vector<int>>&dp){
        if(curr==n){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int include=0;
        if(prev==-1 || arr[curr]>arr[prev]){
            include=1+solve(arr,n,curr+1,curr,dp);
        }
        
        int exclude=solve(arr,n,curr+1,prev,dp);
        
        dp[curr][prev+1]=max(include,exclude);
        return dp[curr][prev+1];
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>>dp(n,vector<int>(n+1,-1));
       int ans=solve(a,n,0,-1,dp);
       return ans;
    }