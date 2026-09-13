/*
You are given an m x n board containing 'X' and 'O'.
A region is a connected group of 'O' cells connected horizontally or vertically.

A region is surrounded if none of its 'O' cells lie on the boundary of the board.
Capture all surrounded regions by replacing their 'O's with 'X's in-place.

Example:
Input:
[
  ["X","X","X","X"],
  ["X","O","O","X"],
  ["X","X","O","X"],
  ["X","O","X","X"]
]

Output:
[
  ["X","X","X","X"],
  ["X","X","X","X"],
  ["X","X","X","X"],
  ["X","O","X","X"]
]

The connected region in the middle is surrounded, so it is captured.
The 'O' at the bottom is on the boundary, so it is not captured.
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vis,boardcopy;
bool boundary;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void dfs(int i,int j,vector<vector<char>>&grid,int n,int m){
    vis[i][j]=1;
    boardcopy[i][j]=1;
    if(i==0||i==m-1||j==0||j==n-1) boundary=true;
    for(int k=0;k<4;k++){
        int ni=i+dx[k],nj=j+dy[k];
        if(ni>=0&&ni<m&&nj>=0&&nj<n&&grid[ni][nj]=='O'&&!vis[ni][nj])
            dfs(ni,nj,grid,n,m);
    }
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<char>>grid(m,vector<char>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) cin>>grid[i][j];

    vis.assign(m,vector<int>(n,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='O'&&!vis[i][j]){
                boundary=false;
                boardcopy.assign(m,vector<int>(n,0));
                dfs(i,j,grid,n,m);
                if(!boundary)
                    for(int k=0;k<m;k++)
                        for(int l=0;l<n;l++)
                            if(boardcopy[k][l]) grid[k][l]='X';
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) cout<<grid[i][j]<<" ";
        cout<<'\n';
    }
}