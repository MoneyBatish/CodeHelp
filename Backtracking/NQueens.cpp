#include <bits/stdc++.h>
void addSolution(vector<vector<int>>&ans,vector<vector<int>>&board,int n) {
	vector<int>temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}
bool isSafe(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&board,int n){
	int i=row;
	int j=col;
	while(j>=0){
		if(board[i][j]==1){
			return false;
		}
		j--;
	}
	i=row;
	j=col;
	while(i>=0 && j>=0){
		if(board[i][j]==1){
			return false;
		}
		i--;
		j--;
	}
	i=row;
	j=col;
	while(i<n && j>=0){
		if(board[i][j]==1){
			return false;
		}
		i++;
		j--;
	}
	return true;
}
void solve(int col,vector<vector<int>>&ans,vector<vector<int>>&board,int n){
	if(col==n){
		addSolution(ans,board,n);
		return;
	}
	for(int row=0;row<n;row++){
		if(isSafe(row,col,ans,board,n)){
			board[row][col]=1;
			solve(col+1,ans,board,n);
			board[row][col]=0;
		}
	}
}
vector<vector<int>> nQueens(int n)
{
	// Write your code here
	vector<vector<int>>ans;
	vector<vector<int>>board(n,vector<int>(n,0));
	solve(0,ans,board,n);
	return ans;
	
}