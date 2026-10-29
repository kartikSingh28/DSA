/*
Topological Sort (DFS)
Given a DAG, print an order where every edge u -> v has u before v.
(Add a node after all its children are done, then reverse the list.)
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;
int n, m;
vector<int> topo;

void dfs_topo(int node)
{
    vis[node] = 1;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs_topo(v);
        }
    }
    topo.push_back(node);
}

int main()
{
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        g[l].push_back(r);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs_topo(i);
        }
    }
    reverse(topo.begin(), topo.end());

    for (int i = 0; i < topo.size(); i++)
    {
        cout << topo[i] << " ";
    }
}