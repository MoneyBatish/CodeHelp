#include<bits/stdc++.h>
using namespace std;
int solve(int i,int arr[],int n,int count,int sum,vector<int> ans){
    if(i==n){
        if(count==sum){
            for(int j=0;j<ans.size();j++){
                cout<<ans[j]<<" ";
            }
            cout<<endl;
            return 1;
        }
        else{
            return 0;
        }
    }
    ans.push_back(arr[i]);
    int Pinc=solve(i+1,arr,n,count+arr[i],sum,ans);
    ans.pop_back();
    ans.push_back(-1*arr[i]);
    int Ninc=solve(i+1,arr,n,count-arr[i],sum,ans);
    ans.pop_back();
    int Excl=solve(i+1,arr,n,count,sum,ans);

    return Pinc+Ninc+Excl;
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
    vector<int> out;
    int ans=solve(0,arr,n,0,sum,out);
    cout<<"Count Is "<<ans<<endl;
}