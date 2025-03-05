// 785. Is Graph Bipartite?
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool dfs(int node, int color, vector<int> &vis, vector<vector<int>> &graph)
{
    vis[node] = color;

    for (auto it : graph[node])
    {
        if (vis[it] == -1)
        {
            if (dfs(it, !color, vis, graph) == false)
                return false;
        }
        else if (vis[it] == color)
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> vis(V, -1);

    for (int i = 0; i < V; ++i)
    {
        if (vis[i] == -1)
        {
            if (dfs(i, 0, vis, graph) == false)
                return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}