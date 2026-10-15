/*
LC 1091 - Shortest Path in Binary Matrix

Given an n x n grid of 0s and 1s. 0 = open cell, 1 = blocked.
Find the length of the shortest clear path from top-left (0,0) to bottom-right (n-1,n-1).
A clear path visits only 0-cells, and you can move in all 8 directions
(up, down, left, right and the 4 diagonals).
Path length = number of cells visited on the path (start and end included).
Return -1 if no clear path exists.
Constraints: 1 <= n <= 100

Example:
grid = {{0,0,0},
        {1,1,0},
        {1,1,0}}
Output: 4
*/
#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> grid;
vector<vector<int>> dist;
int dx[8]={-1,1,0,0,1,-1,-1,1};
int dy[8]={0,0,-1,1,1,1,-1,-1};

void solve(){
    cin>>n;
    grid.resize(n,vector<int>(n));
    dist.assign(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    if(grid[0][0]==1 || grid[n-1][n-1]==1){
        cout<<-1<<endl;
        return;
    }
    queue<pair<int,int>> q;
    int sx=0,sy=0;
    q.push({sx,sy});
    dist[sx][sy]=1;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int currx=it.first;
        int curry=it.second;
        if(currx==n-1 && curry==n-1){
            cout<<dist[currx][curry]<<endl;
            return;
        }
        for(int i=0;i<8;i++){
            int nx=currx+dx[i];
            int ny=curry+dy[i];
            if(nx>=0 && nx<n && ny>=0 &&ny<n){
                if(grid[nx][ny]!=1 && dist[nx][ny]==-1){
                    dist[nx][ny]=dist[currx][curry]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    cout<<-1<<endl;
}

int main(){
    solve();
    return 0;
}