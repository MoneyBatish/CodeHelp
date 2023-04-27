#include<bits/stdc++.h>
using namespace std;
int solve(int i,int arr[],int n,int count,int sum,vector<vector<int>>&dp){
    if(i==n){
        if(count==sum){
            return 1;;
        }
        else{
            return 0;
        }
    }
    if(dp[i][count]!=-1){
        dp[i][count];
    }
    int Pinc=solve(i+1,arr,n,count+arr[i],sum,dp);
    int Ninc=solve(i+1,arr,n,count-arr[i],sum,dp);
    int Excl=solve(i+1,arr,n,count,sum,dp);

    dp[i][count]=Pinc+Ninc+Excl;
    return dp[i][count];
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));

    int ans=solve(0,arr,n,0,sum,dp);
    cout<<"Count Is "<<ans<<endl;
}