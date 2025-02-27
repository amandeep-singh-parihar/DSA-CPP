#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(N) + O(2E)
// SC O(N) + O(N) + O(N) = O(N)
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, ls);
        }
    }
}

vector<int> dfsOfGraph(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<int> vis(V, 0);
    int start = 0;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
}

int main()
{
    //      0
    //     / \
    //    1   2
    //   / \
    //  3   4

    int V = 5; // Number of vertices
    vector<vector<int>> adj(V);

    // Hardcoded edges
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    vector<int> dfsTraversal = dfsOfGraph(adj);

    cout << "DFS Traversal: ";
    for (int node : dfsTraversal)
    {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}