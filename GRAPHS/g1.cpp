#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> visited;
vector<int> nodecol;

int dfs(int node,int color){
    //function
    nodecol[node]=color;
    visited[node]=1;
    for(auto v:g[node]){
        if(!visited[v]){
            dfs(v,color);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    visited.resize(n+1);
    nodecol.resize(n+1);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int color=0;
    // color saves no of component;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            color++;
            dfs(i,color);
        }
    }
    cout<<color<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<nodecol[i]<<"\n";
    }
    cout<<endl;

    vector<int> colnodes[color+1];
    for(int i=1;i<=n;i++){
        colnodes[nodecol[i]].push_back(i);//nodes in a component
    }

    for(int i=1;i<=color;i++){
        cout<<i<<":[";
        for(auto v:colnodes[i]){
            cout<<v<<",";
        }
        cout<<"]"<<endl;
    }
    cout<<endl;

    vector<int> compsize;
    for(int i=1;i<=color;i++){
        compsize.push_back(colnodes[i].size());
    }
    for(auto v:compsize){
        cout<<v<<" ";
    }
    int ans=0;
    for(auto v:compsize){
        ans+=v*(n-v);
    }
    ans/=2;

    //for q ueries to find wheter they are in a component or not
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(nodecol[x]==nodecol[y]){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}