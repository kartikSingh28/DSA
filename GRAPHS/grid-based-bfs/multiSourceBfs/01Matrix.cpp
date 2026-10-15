/*Given an nx m binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
vector<vector<int>> dist;
int n,m;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

vector<vector<int>> solve(){
    grid.resize(n,vector<int>(m));
    dist.assign(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0 && dist[i][j]==-1){
                q.push({i,j});
                dist[i][j]=0;
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
                if(dist[nx][ny]==-1){
                    dist[nx][ny]=dist[currx][curry]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    return dist;
}

int main(){
    cin>>n>>m;
    vector<vector<int>> res=solve();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}