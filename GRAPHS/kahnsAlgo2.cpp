#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;
int n,m;
//for lexographical smallest topological order

void kahns(){
    priority_queue<int> q;
    for(int i=0;i<=n;i++){
        if(indeg[i]==0){
            q.push(-i);
        }
    }
    while(!q.empty()){
        int curr=-q.top();
        q.pop();
        topo.push_back(curr);
        for(auto v:g[curr]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(-v);
            }
        }
    }
}


signed main(){
    cin>>n>>m;
    g.resize(n+1);
    indeg.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
    }
    kahns();
    if(topo.size()!=n){
        cout<<"Cycle exists "<<"\n";
    }else{
        for(auto v:topo){
            cout<<v<<" ";
        }
    }
    
}
