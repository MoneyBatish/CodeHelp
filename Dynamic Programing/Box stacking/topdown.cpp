bool check(vector<int>&base,vector<int>&newbox){
    if(newbox[0]<=base[0] && newbox[1]<=base[1] && newbox[2]<=base[2]){
        return true;
    }
    else{
        return false;
    }
}
int solve(vector<vector<int>>& arr,int n,int curr,int prev,vector<vector<int>>&dp){
        if(curr==n){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int include=0;
        if(prev==-1 || check(arr[curr],arr[prev])){
            include=arr[curr][2]+solve(arr,n,curr+1,curr,dp);
        }
        
        int exclude=solve(arr,n,curr+1,prev,dp);
        
        dp[curr][prev+1]=max(include,exclude);
        return dp[curr][prev+1];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a:cuboids){
            sort(a.begin(),a.end());
        }
        sort(cuboids.begin(),cuboids.end());
        vector<vector<int>>dp(cuboids.size()+1,vector<int>(cuboids.size()+1,-1));
        return solve(cuboids,cuboids.size(),0,-1,dp);
    }