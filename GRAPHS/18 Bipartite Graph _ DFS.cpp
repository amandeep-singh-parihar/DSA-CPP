// 785. Is Graph Bipartite?
#include <bits/stdc++.h>
using namespace std;
// r1
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool dfs(int node, int color, vector<int> &vis, vector<vector<int>> &graph)
{
    vis[node] = color; // mark the node as color = 0

    for (auto it : graph[node])
    {
        if (vis[it] == -1)
        {
            if (dfs(it, !color, vis, graph) == false) // the node which is not visited mark it as color = 1
                return false;
        }
        else if (vis[it] == color) // if there is already a color and it is same as the color the it means two adjacent nodes do have same color hence no bipartite
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> vis(V, -1); // lets mark the visited array as -1 it means no color

    for (int i = 0; i < V; ++i)
    {
        if (vis[i] == -1)
        {
            if (dfs(i, 0, vis, graph) == false) // color = 0
                return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}