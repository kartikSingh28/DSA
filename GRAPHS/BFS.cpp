#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);//directed graph
    }
    int source;
    cin>>source;

    //bfs
    vector<int> dist(n+1,-1);
    queue<int> q;

    q.push(source);
    dist[source]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();

        for(auto neigh:g[curr]){
            if(dist[neigh]==-1){
                dist[neigh]=dist[curr]+1;
                q.push(neigh);
            }
        }

    }
    /// if a node dist[node]==-1 still after bfs it means it is unreachable from source node
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";//shortest path from source node
    }
    cout<<"\n";
}