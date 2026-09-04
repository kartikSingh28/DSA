// DSU: n elements (0...n-1), q queries:
// 0 x y -> unite the sets containing x,y
// 1 x y -> print 1 if x,y are in same set, else 0

#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> rnk;

int find(int i,vector<int> &parent){
    if(i==parent[i]){
        return i;
    }
    return parent[i]=find(parent[i],parent);
}

void unite(int x,int y,vector<int>&parent,vector<int> &rnk){
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

bool same(int x,int y){
    int par_x=find(x,parent);
    int par_y=find(y,parent);

    if(par_x==par_y){
        return true;
    }
    else{
        return false;
    }
}

void solve(){
    int n,q;
    cin>>n>>q;
    parent.resize(n+1);
    rnk.assign(n+1,0);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    while(q--){
        int com,x,y;
        cin>>com>>x>>y;
        if(com==0){
            unite(x,y,parent,rnk);
        }else{
            bool res=same(x,y);
            if(res){
                cout<<"1"<<endl;
            }else{
                cout<<"0"<<endl;
            }
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
        solve();
}