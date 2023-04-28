int solve(vector<int>&values,int i,int j){
        if(i+1==j){
            return 0;
        }

        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans=min(ans,values[i]*values[k]*values[j]+solve(values,i,k)+solve(values,k,j));
        }
        return ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        int ans=solve(values,0,n-1);
        return ans;
    }