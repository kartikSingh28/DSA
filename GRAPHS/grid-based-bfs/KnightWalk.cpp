/*
KWALK

Solved
Time Limit: 10 sec
Memory Limit: 256 MB

Description:
You are given an N × N chessboard and a knight with starting position
(Sx, Sy). You are given a final position (Fx, Fy). You have to find
the minimum number of moves required to reach the final position.

Complete the function.

Example:

Input:
N = 8
Sx = 0, Sy = 0
Fx = 7, Fy = 7

Output:
6

Explanation:
The minimum number of knight moves required to reach (7, 7)
from (0, 0) on an 8 × 8 chessboard is 6.
*/
#include <bits/stdc++.h>
using namespace std;
int dx[8]={-2,2,-1,1,-2,2,-1,1};
int dy[8]={-1,-1,2,2,1,1,2,2};

int KnightWalk(int n,int sx,int sy,int fx,int fy){
    vector<vector<int>> dist(n+1,vector<int>(n+1,-1));
    queue<pair<int,int>> q;
    q.push({sx,sy});
    dist[sx][sy]=0;

    while(!q.empty()){
        auto it =q.front();
        q.pop();
        int currx=it.first;
        int curry=it.second;
        if(currx==fx && curry==fy){
            return dist[currx][curry];
        }
        for(int i=0;i<8;i++){
            int neighx=currx+dx[i];
            int neighy=curry+dy[i];
            if(neighx>=1 && neighx<=n && neighy>=1 && neighy<=n){
                if(dist[neighx][neighy]==-1){
                    dist[neighx][neighy]=dist[currx][curry]+1;
                    q.push({neighx,neighy});
                }
            }
        }
    }
    return -1;
}

signed main(){
    int n,sx,sy,fx,fy;
    cin>>n>>sx>>sy>>fx>>fy;
    cout<<KnightWalk(n,sx,sy,fx,fy)<<endl;
    
}