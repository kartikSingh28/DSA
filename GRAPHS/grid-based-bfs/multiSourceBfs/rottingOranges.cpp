/*
Rotting Oranges (LC 994)
Given an n x m grid:
0 = Empty, 1 = Fresh orange, 2 = Rotten orange.
Every minute, rotten oranges infect adjacent fresh oranges
in 4 directions.
Return the minimum time to rot all oranges, or -1 if impossible.

Example:
grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
vector<vector<int>> Time;
int n,m;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int solve(){
    cin>>n>>m;
    grid.resize(n,vector<int>(m));
    Time.assign(n+1,vector<int>(m+1,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2 && Time[i][j]==-1){
                q.push({i,j});
                Time[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int currx=it.first;
        int curry=it.second;
        for(int i=0;i<4;i++){
            int nx=currx+dx[i];
            int ny=curry+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(grid[nx][ny]!=0 && Time[nx][ny]==-1){
                    Time[nx][ny]=Time[currx][curry]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && Time[i][j]==-1){
                return -1;
            }
            if(grid[i][j]==1 || grid[i][j]==2){
                ans=max(ans,Time[i][j]);
            }
        }
    }
    return ans;

}

int main(){
    int res=solve();
    cout<<res<<endl;
    return 0;
}