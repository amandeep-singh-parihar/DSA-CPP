// Minimum Spanning Tree
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Only gives the MST sum
// TC O(ElogE + ElogE)
// SC O(E)
int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int sum = 0;
    vector<int> vis(V, 0);
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;
        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeW = it[1];
            if (!vis[adjNode])
            {
                pq.push({edgeW, adjNode});
            }
        }
    }
    return sum;
}

// Also needs the edges which are in the MST
vector<pair<int, int>> _spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    // wt,node,parent
    pq.push({0, {0, -1}});
    vector<int> vis(V, 0);
    vector<pair<int, int>> MST;
    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;
        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        sum += wt;
        if (parent != -1)
            MST.push_back({node, parent}); // storing the sequence
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeW = it[1];
            if (!vis[adjNode])
            {
                pq.push({edgeW, {adjNode, node}});
            }
        }
    }
    cout << sum << endl;
    return MST;
}

int main()
{
    int V = 5; // Number of vertices
    vector<vector<int>> adj[V];

    // Hardcoded edges: {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 4, 2}, {2, 3, 2}, {3, 4, 1}};

    // Construct adjacency list
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // Since it's an undirected graph
    }

    // Compute and print the weight of the Minimum Spanning Tree (MST)
    int mstWeight = spanningTree(V, adj);
    cout << "Minimum Spanning Tree Weight: " << mstWeight << endl;

    vector<pair<int, int>> ans = _spanningTree(V, adj);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << "(" << ans[i].first << "," << ans[i].second << ")" << " ";
    }

    return 0;
}