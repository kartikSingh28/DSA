#include <bits/stdc++.h>
using namespace std;
int n,m;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<vector<int>> dist;

void multisourceBFS(vector<vector<int>> &grid){

    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='s'){
                q.push({i,j});
                dist[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int x=it.first;
        int y=it.second;
        for(int i=0;i<4;i++){
            int neighx=x+dx[i];
            int neighy=y+dy[i];

            if(neighx>=0 && neighx<n && neighy>=0 && neighy<m){
                if(grid[neighx][neighy]!=0 && dist[neighx][neighy]==-1){
                    dist[neighx][neighy]=dist[x][y]+1;
                    q.push({neighx,neighy});
                }
            }
        }
    }

}

int main(){
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,-1));
    dist.assign(n,vector<int>(m,-1));

    return 0;

}