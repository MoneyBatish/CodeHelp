#include<bits/stdc++.h>
bool isCyclicDFS(int node,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,unordered_map<int,bool>&DFSvisited){
  visited[node]=true;
  DFSvisited[node]=true;
  for(auto i:adj[node]){
    if(!visited[i]){
      if(isCyclicDFS(i,adj,visited,DFSvisited)){
        return true;
      }
    }
    else if(DFSvisited[i]){
        return true;
    }
  }
  DFSvisited[node]=false;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>>adj;
  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;
    adj[u].push_back(v);
  }
  unordered_map<int,bool>visited;
  unordered_map<int,bool>DFSvisited;
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      if(isCyclicDFS(i,adj,visited,DFSvisited)){
        return true;
      }
    }
  }
  return false;
}