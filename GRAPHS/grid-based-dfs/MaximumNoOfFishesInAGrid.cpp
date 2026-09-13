#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> vis;
int sz;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void dfs(int i,int j,vector<vector<int>> &grid,int n,int m){
    sz+=grid[i][j];
    vis[i][j]=1;

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

int main(){
    cin>>n>>m;
    vector<vector<int>> grid(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vis.assign(n+1,vector<int>(m+1,0));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sz=0;
            if(grid[i][j]==1 && !vis[i][j]){
                dfs(i,j,grid,n,m);
                ans=max(ans,sz);
            }
        }
    }
    cout<<ans<<endl;
    return 0;

}