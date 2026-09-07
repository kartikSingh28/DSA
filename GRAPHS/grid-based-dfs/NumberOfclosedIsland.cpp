// Given a 2D grid of 0s (land) and 1s (water), count the number of islands
// made of 0s that are completely surrounded by 1s on all four sides.

/*Input:
grid = [
    [1,1,1,1,1,1,1],
    [1,0,0,0,0,0,1],
    [1,0,1,1,1,0,1],
    [1,0,1,0,1,0,1],
    [1,0,1,1,1,0,1],
    [1,0,0,0,0,0,1],
    [1,1,1,1,1,1,1]
]
Output:
2*/

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
            if(grid[neighx][neighy]==0 && !vis[neighx][neighy]){
                dfs(neighx,neighy,grid,n,m);
            }
        }
    }
}

int solve(vector<vector<int>> &grid){
    vis.assign(n+1,vector<int>(m+1,0));
    int comp=0;
    int bound_comp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0 && !vis[i][j]){
                comp++;
                boundary=false;
                dfs(i,j,grid,n,m);
                if(boundary){
                    bound_comp++;
                }
            }
        }
    }
    return comp-bound_comp;
}

int main(){
    cin>>n>>m;
    grid.resize(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<solve(grid);
    return 0;

}
