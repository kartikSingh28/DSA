#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
using lli = long long;

class priortize {
public:
    bool operator()(const ii &p1, const ii &p2) const {   // const refs required
        return p1.second > p2.second;                     // min-heap on distance
    }
};

int n, m;
vector<ii> g[100100];
lli dist_[100100];
int vis[100100];

void dijkstra(int src){
    for(int i = 1; i <= n; i++){
        dist_[i] = 1e18;
        vis[i] = 0;
    }
    dist_[src] = 0;

    priority_queue<ii, vector<ii>, priortize> pq;
    pq.push({src, 0});                        // {node, distance}

    while(!pq.empty()){
        ii fs = pq.top();
        pq.pop();
        int u = fs.first;

        if(vis[u]) continue;
        vis[u] = 1;

        for(auto v : g[u]){
            int neigh = v.first;
            int wt = v.second;
            if(dist_[neigh] > dist_[u] + wt){
                dist_[neigh] = dist_[u] + wt;
                pq.push({neigh, dist_[neigh]});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    dijkstra(1);

    for(int i = 1; i <= n; i++) cout << dist_[i] << " ";
    cout << "\n";
}