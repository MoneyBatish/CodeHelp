#include <bits/stdc++.h>
int solve(vector<int>&num,int target){
    if(target==0){
        return 1;
    }
    if(target<0){
        return 0;
    }

    int ans=0;
    for(int i=0;i<num.size();i++){
        ans+=solve(num,target-num[i]);
    }

    return ans;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int ans=solve(num,tar);
    return ans;
}