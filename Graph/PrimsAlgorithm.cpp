#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<g.size();i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int>key(n+1);
    vector<bool>mst(n+1);
    vector<int>parent(n+1);
    for(int i=0;i<=n;i++){
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;
    }
    key[1]=0;
    for(int i=1;i<=n;i++){
        int mini=INT_MAX;
        int u;
        for(int j=1;j<=n;j++){
            if((mst[j]==false) && key[j]<mini){
                mini=key[j];
                u=j;
            }
        }
        mst[u]=true;
        for(auto it:adj[u]){
            if(mst[it.first]==false && key[it.first]>it.second){
                parent[it.first]=u;
                key[it.first]=it.second;
            }
        }
    }
    vector<pair<pair<int, int>, int>>ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}
