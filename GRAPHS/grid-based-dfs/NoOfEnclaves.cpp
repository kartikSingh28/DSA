/*You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.*/

/*Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:*/

#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> grid;
vector<vector<int>> vis;
bool boundary;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void dfs(int i,int j,vector<vector<int>> &grid,int n,int m){
    vis[i][j]=1;
    if(i==0 || i==n-1 || j==0 || j==m-1){
        boundary=true;
    }
    for(int k=0;k<4;k++){
        int neighx=i+dx[k];
        int neighy=j+dy[k];
        if(neighx>=0 && neighx<n && neighy>=0 && neighy<m){
            if(grid[neighx][neighy]==1 && !vis[neighx][neighy]){
                dfs(neighx,neighy,grid,n,m);
            }
        }
    }
}

int solve(vector<vector<int>> &grid){
    vis.assign(n+1,vector<int>(m+1,0));
    int sz;
    int ans=0;
    for(int i=0;i<n;i++){
        sz=0;
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && !vis[i][j]){
                sz++;
                dfs(i,j,grid,n,m);
                if(!boundary){
                    ans+=sz;
                }
            }
        }
    }
    return ans;
}


signed main(){
    cin>>n>>m;
    grid.resize(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<solve(grid)<<endl;
}

