// all pair shortest path
#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dist;
vector<vector<int>> par;

void solve(){
    int n,m;
    cin>>n>>m;

    dist.assign(n+1,vector<long long>(n+1,1e18));

    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],1LL*c);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}