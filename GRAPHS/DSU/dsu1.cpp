#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int i,vector<int> &parent){
    if(i==parent[i]){
        return i;
    }
    return find(parent[i],parent);
}

void Union(int x,int y){

    int par_x=find(x,parent);
    int par_y=find(y,parent);
    if(par_x!=par_y){
        parent[par_x]=par_y;
    }
}

void solve(){

    int n;
    cin>>n;

    parent.resize(n+1);

    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}