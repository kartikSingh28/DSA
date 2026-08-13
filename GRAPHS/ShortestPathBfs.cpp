#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> dist;
vector<int> par;

int main(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    
    dist.assign(n+1,-1);
    par.assign(n+1,-1);

    int source,end;
    cin>>source>>end;
    queue<int> q;

    q.push(source);
    dist[source]=0;

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int neigh:g[curr]){
            if(dist[neigh]==-1){
                dist[neigh]=dist[curr]+1;
                //curr->neigh
                par[neigh]=curr;
                q.push(neigh);
            }
        }

    }
    //dist[u]==-1 u not reachable from source
    if(dist[end]==-1){
        cout<<"-1"<<endl;
    }else{
        vector<int> path;
        int temp=end;
        while(temp!=source){
            path.push_back(temp);
            temp=par[temp];
        }
        path.push_back(source);
        reverse(path.begin(),path.end());
        for(int u:path){
            cout<<u<<" ";
        }
    }

    return 0;
}