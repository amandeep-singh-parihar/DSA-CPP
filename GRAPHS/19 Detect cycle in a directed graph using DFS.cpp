// Cycle in a Directed Graph
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis)
{
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, adj, vis, pathVis))
                return true;
        }
        else if (pathVis[it])
        {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}

bool isCyclic(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    for (int i = 0; i < V; ++i)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pathVis))
                return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}