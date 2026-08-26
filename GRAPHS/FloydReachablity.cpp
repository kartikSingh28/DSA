// to detect a node is reachablity using floyd warshal

#include <bits/stdc++.h>
using namespace std;
const long long INF=1e18;
int n,m;
vector<vector<int>> edges;
vector<vector<long long>> dist;

void solve(){
    dist.assign(n,vector<long long>(n,INF));
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(disr)
            }
        }
    }
}

signed main(){
    cin>>n>>m;
    edges.resize(m);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges[i]={a,b};
    }
    
}