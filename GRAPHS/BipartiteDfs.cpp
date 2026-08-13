#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col;
bool ok=true;

void dfs(int node,int color){
    col[node]=color;
    for(auto v:g[node]){
        if(col[v]==-1){
            dfs(v,1-color);
            if(!ok) return;
        }else if(col[v]==color){
            ok=false;
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1,-1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(col[i]==-1){
            dfs(i,0);
            if(!ok) break;
        }
    }
    if(ok){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}