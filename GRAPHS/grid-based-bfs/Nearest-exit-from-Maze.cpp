/*
LC 1926 - Nearest Exit from Entrance in Maze

'.' = empty, '+' = wall. Start at entrance = [row, col], move up/down/left/right.
Return min steps to any border cell (entrance itself is NOT an exit), else -1.

Example:
+ + . +
. . . +      entrance = {1,2}
+ + + .      Output: 1  ([0,2] in 1 step; [1,0] needs 2; [2,3] unreachable)
*/
#include <bits/stdc++.h>
using namespace std;

class Answer{
    public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    int nearestExit(vector<vector<char>> &maze,vector<int> &entrace){
        int m=maze.size();
        int n=maze[0].size();
        int sx=entrace[0];
        int sy=entrace[1];
        vector<vector<int>> dist(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        q.push({sx,sy});
        dist[sx][sy]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int currx=it.first;
            int curry=it.second;
            for(int i=0;i<4;i++){
                int nx=currx+dx[i];
                int ny=curry+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(maze[nx][ny]!='+' && dist[nx][ny]==-1){
                        dist[nx][ny]=dist[currx][curry]+1;
                        q.push({nx,ny});
                    }
                }
            }

        }
        int minDist=INT_MAX;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && dist[i][j]!=-1 && !(i==sx && j==sy)){
                    minDist=min(minDist,dist[i][j]);
                }
            }
        }
        if(minDist==INT_MAX){
            return -1;
        }
        return minDist;

    }
};
