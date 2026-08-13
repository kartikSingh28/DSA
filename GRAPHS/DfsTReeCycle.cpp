// for directed graph
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> col;
bool isCycle=false;

void dfs(int node){
    col[node]=2;
    for(auto v:g[node]){
        if(col[v]==1){
            // node v is a forward edge
            dfs(v);
        }else if(col[v]==2){
            // node v is backward edge
            isCycle=true;
        }else if(col[v]==3){
            ///node v is cross edge
        }
        col[node]=3;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    g.resize(n+1);
    col.assign(n,1);
    for(int i=0;i<m;i++){
        int a=edges[i][0];
        int b=edges[i][1];
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(col[i]==1){
            dfs(i);
        }
    }
    if(isCycle){
        cout<<"Cycle present";
    }else{
        cout<<"NO cycle";
    }
    return 0;
}