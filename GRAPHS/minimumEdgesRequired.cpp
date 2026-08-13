/*Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
Your task is to find out the minimum number of roads required, and also determine which roads should be built.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.
Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.*/

/*Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
4 2
1 2
3 4

Output:
1
2 3*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> visited;
vector<int> nodecol;
vector<int> representative;



void dfs(int node,int color){
    nodecol[node]=color;
    visited[node]=1;
    for(auto v:adj[node]){
        if(!visited[v]){
            dfs(v,color);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges[i]={a,b};
    }
    adj.resize(n+1);
    visited.assign(n+1,0);
    nodecol.resize(n+1);
    for(int i=0;i<m;i++){
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int color=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            color++;
            representative.push_back(i);
            dfs(i,color);
        }
    }
    int k=color-1;
    cout<<k<<endl;
    for(int i=0;i<k;i++){
        cout<<representative[i]<<" "<<representative[i+1]<<endl;
    }

    return 0;
}