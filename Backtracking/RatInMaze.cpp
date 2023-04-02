#include <bits/stdc++.h>
bool isSafe(int x,int y,vector < vector < int >> & arr,int n,vector<vector<bool>>&visited){
    if((x>=0 && x<n) && (y>=0 && y<n) && arr[x][y]==1 && visited[x][y]==0){
        return true;
    }
    return false;
}
void solve(int x,int y,vector < vector < int >> & arr,int n,vector<string>&ans,
vector<vector<bool>>&visited,string path){
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    visited[x][y]=1;
    //Down
    if(isSafe(x+1,y,arr,n,visited)){
        solve(x+1,y,arr,n,ans,visited,path+"D");
    }
    //Left
    if(isSafe(x,y-1,arr,n,visited)){
        solve(x,y-1,arr,n,ans,visited,path+"L");
    }
    //Right
    if(isSafe(x,y+1,arr,n,visited)){
        solve(x,y+1,arr,n,ans,visited,path+"R");
    }
    //UP
    if(isSafe(x-1,y,arr,n,visited)){
        solve(x-1,y,arr,n,ans,visited,path+"U");
    }
    visited[x][y]=0;

}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    if(arr[0][0]==0){
        return{};
    }
    vector<string>ans;
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    string path="";
    solve(0,0,arr,n,ans,visited,path);
    return ans;    
}