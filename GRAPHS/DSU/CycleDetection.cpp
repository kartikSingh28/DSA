#include <bits/stdc++.h>

using namespace std;// agr cycle hogi toh kisi 1 point of time pr find(x)==find(y) agr hogya to cycle hai wrna union krte rho

vector<vector<int>> adj;
vector<int> parent;
vector<int> rnk;

int find(int i,vector<int> &parent){
    if(i==parent[i]){
        return i;
    }
    return parent[i]=find(parent[i],parent);
}

void Union(int x,int y,vector<int> &parent,vector<int> &rnk){

    int par_x=find(x,parent);
    int par_y=find(y,parent);
    if(par_x==par_y) return;

    if(rnk[par_x]>rnk[par_y]){
        parent[par_y]=par_x;
    }else if(rnk[par_y]>rnk[par_x]){
        parent[par_x]=par_y;
    }else{
        parent[par_x]=par_y;
        rnk[par_y]++;
    }
}

int main(){

    int v,m;//no of vertices,edges
    cin>>v>>m;

    adj.resize(v+1);
    parent.resize(v+1);
    rnk.assign(v+1,0);

    for(int i=1;i<=v;i++){
        parent[i]=i;
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int u=1;u<=v;u++){
        for(auto v:adj[u]){
            if(u<v){
                int par_u=find(u,parent);
                int par_v=find(v,parent);
                if(par_u==par_v){
                    cout<<"true"<<endl;
                    return 0;
                }
                Union(u,v,parent,rnk);
            }
        }
    }
    cout<<"false"<<endl;

    return 0;
}