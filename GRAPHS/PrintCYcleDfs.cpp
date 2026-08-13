#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> col;
vector<int> parent;
bool isCycle=0;
vector<int> any_cycle;

void dfs(int node,int par){
    parent[node]=par;
    col[node]=2;
    for(auto v:g[node]){
        if(col[v]==1){
            dfs(v,node);
        }else if(col[v]==2){
            if(isCycle==0){
                int temp=node;
                while(temp!=v){
                    any_cycle.push_back(temp);
                    temp=parent[temp];      // FIX: was parent[node]
                }
                any_cycle.push_back(temp);
                reverse(any_cycle.begin(),any_cycle.end());
            }
            isCycle=1;
        }
    }
    col[node]=3;
}


int main(){
    int n,m;
    cin>>n>>m;
    g.resize(n);
    col.assign(n,1);
    parent.assign(n,-1);            // FIX: was 1, a real vertex id
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;                  // FIX: edges were never read
        g[a].push_back(b);
    }
    for(int i=0;i<n;i++){
        if(col[i]==1){
            dfs(i,-1);              // FIX: sentinel, was 0
        }
    }
    if(isCycle){
        for(auto v:any_cycle){
            cout<<v<<" ";
        }
    }else{
        cout<<"No Cycle";
    }
    return 0;
}