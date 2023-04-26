#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    unordered_map<int,list<pair<int,int>>>adj;
    void addAdj(int u,int v,int weight){
        pair<int,int>p=make_pair(v,weight);
        adj[u].push_back(p);
    }
    void DFS(int node,vector<int,bool>&visited,stack<int>&s){
        visited[node]=true;
        for(auto i:adj[])
    }

    void printAdj(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<"{"<<j.first<<","<<j.second<<"},";
            }
            cout<<endl;
        }
    }

};
int main()
{
    graph g;
    g.addAdj(0,1,5);
    g.addAdj(0,2,3);
    g.addAdj(1,2,2);
    g.addAdj(1,3,6);
    g.addAdj(2,3,7);
    g.addAdj(2,4,4);
    g.addAdj(2,5,2);
    g.addAdj(3,4,-1);
    g.addAdj(4,5,-2);
    int n=6;
    vector<int,bool>visited;
    stack<int>s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFS(i,visited,s);
        }
    }
}