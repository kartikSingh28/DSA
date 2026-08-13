#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // dimensins of grid
    int n,m;
    cin>>n>>m;
    vector<vector<bool>> grid(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='*'){
                //cell (i,j) is blocked
                grid[i][j]=true;
            }else{
                grid[i][j]=false;
            }
        }
    }
    // start cell (sx,sy)   end cell (ex,ey)
    int sx,sy,ex,ey;
    cin>>sx>>sy>>ex>>ey;
    //bfs
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    vector<vector<int>> dist(n,vector<int>(m,-1));
    queue<pair<int,int>> q;
    dist[sx][sy]=0;
    q.push({sx,sy});
    

    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int currx=it.first;
        int curry=it.second;

        if(currx==ex &&curry==ey){//optimization
            break;
        }
        for(int i=0;i<4;i++){
            int neighx=currx+dx[i];
            int neighy=curry+dy[i];

            //boundary condn
            if(neighx>=0 && neighx<n  &&neighy>=0 &&neighy<m){
                if(!grid[neighx][neighy]){
                    if(dist[neighx][neighy]==-1){
                        dist[neighx][neighy]=dist[currx][curry]+1;
                        q.push({neighx,neighy});
                    }
                }
            }
        }
        if(dist[ex][ey]!=-1){
            break;
        }

    }
    return 0;
}