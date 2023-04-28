class compare{
    public:
    bool operator()(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            if(a[1]>b[1]){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(a[0]>b[0]){
                return false;
            }
            else{
                return true;
            }
        }
    }
};
class Solution {
public:
int solve(vector<vector<int>>& arr,int n){
        vector<int> ans;
       ans.push_back(arr[0][1]);
       for(int i=1;i<n;i++){
           if(arr[i][1]>ans.back()){
               ans.push_back(arr[i][1]);
           }
           else{
               int index=lower_bound(ans.begin(),ans.end(),arr[i][1])-ans.begin();
               ans[index]=arr[i][1];
           }
       }
       return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        compare c;
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),c);
       int ans=solve(envelopes,n);
       return ans;

    }
};