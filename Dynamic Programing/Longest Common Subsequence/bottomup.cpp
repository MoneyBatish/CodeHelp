int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m= text2.length();
        vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans=0;
                if(text1[i]==text2[j]){
                    ans=1+dp[i+1][j+1];
                }
                else{
                    ans=max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }