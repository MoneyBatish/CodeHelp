int solve(int arr[],int n,int curr,int prev){
        if(curr==n){
            return 0;
        }
        
        int include=0;
        if(prev==-1 || arr[curr]>arr[prev]){
            include=1+solve(arr,n,curr+1,curr);
        }
        
        int exclude=solve(arr,n,curr+1,prev);
        
        return max(include,exclude);
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       int ans=solve(a,n,0,-1);
       return ans;
    }