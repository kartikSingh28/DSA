/*
Save Yourself (Escape Monsters)

n x m grid: '.' floor, '#' wall, 'A' you (exactly one), 'M' monster.
Each step you move up/down/left/right, and every monster moves at the same time.
Reach any boundary cell without ever sharing a cell with a monster
(assume the monsters know your path).
Print "YES" and the shortest path length, or "NO".
Constraints: 1 <= n, m <= 1000

Sample:
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######
Output:
YES
5
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
vector<vector<int>> monsterTime;
vector<vector<int>> personTime;
int dx[8]={-1,1,0,0,-1,1,-1,1};
int dy[8]={0,0,-1,1,1,1,-1,-1};
int n,m;

void solve(){
    cin>>n>>m;
    grid.resize(n,vector<char>(m));
    monsterTime.assign(n+1,vector<int>(m+1,-1));
    personTime.assign(n+1,vector<int>(m+1,-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='M' && monsterTime[i][j]==-1){
                q.push({i,j});
                monsterTime[i][j]=0;
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
                if(grid[nx][ny]!='#' && monsterTime[nx][ny]==-1){
                    monsterTime[nx][ny]=monsterTime[currx][curry]+1;
                    q.push({nx,ny});
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((grid[i][j]!='#' && grid[i][j]=='A') && personTime[i][j]==-1){
                q.push({i,j});
                personTime[i][j]=0;
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
                if((grid[nx][ny]!='#' && (personTime[currx][curry]+1<monsterTime[nx][ny] || monsterTime[nx][ny]==-1))&&personTime[nx][ny]==-1){
                    personTime[nx][ny]=personTime[currx][curry]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    //check for exit at boundary
    bool escape=false;
    int minDist=INT_MAX;
    int ex=-1,ey=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0 || i==n-1 || j==0 || j==m-1)&& personTime[i][j]!=-1){
                if(personTime[i][j]<minDist){
                    minDist=personTime[i][j];
                    ex=i;
                    ey=j;
                    escape=true;
                }
            }
        }
    }
    if(escape){
        cout<<"YES"<<endl;
        cout<<personTime[ex][ey]<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main(){
    solve();
    return 0;
}