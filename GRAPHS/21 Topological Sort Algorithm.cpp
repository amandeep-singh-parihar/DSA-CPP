// Topological sort using dfs
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.
// O(2N) + O(N) ~ O(2N): O(2N) for the visited array and the stack carried during DFS calls and O(N) for recursive stack space, where N = no. of nodes.
void dfs(int node, vector<int> &vis, vector<int> &ans, vector<vector<int>> &adj)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, ans, adj);
        }
    }
    ans.push_back(node);
}

vector<int> topologicalSort(vector<vector<int>> &adj)
{
    // if the adjacency list is not given then first convert it into adjacency list
    int V = adj.size();
    vector<int> vis(V, 0);
    vector<int> ans;
    for (int i = 0; i < V; ++i)
    {
        if (!vis[i])
        {
            dfs(i, vis, ans, adj);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}