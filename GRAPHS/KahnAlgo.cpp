// topological ordering using bfs for dag
//if there exits a cycle in a graph and it is applied to it then indeg of one of its vertices in a cycle can never be 0;
// so size of topo vector!=n it can be used to detect cycle also
// also used to print lexographical sortest topological ordring
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;
int n,m;

void kahns(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        topo.push_back(curr);
        for(auto v:g[curr]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(v);
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
    for(auto v:topo){
        cout<<v<<" ";
    }
}