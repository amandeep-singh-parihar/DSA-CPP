#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// DFS
// TC O(N + 2E) + O(N)
// SC O(N) + O(N)
bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[node] = 1;                      // mark the first as visited
    for (auto adjacentNode : adj[node]) // find the adjacentNode in the adj
    {
        if (!vis[adjacentNode]) // if the node is not visited then again call the function
        {
            if (dfs(adjacentNode, node, adj, vis)) // if the DFS after all the calls gives true, return true.
                return true;
        }
        else if (adjacentNode != parent) // if the node is visited and it is not parent it means some one touched it before. result -> cycle
        {
            return true;
        }
    }
    return false;
}

bool isCycle(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<int> vis(V, 0);
    for (int i = 0; i < V; ++i) // this is for disconnected graph
    {
        if (!vis[i])
        {
            if (dfs(i, -1, adj, vis))
                return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}