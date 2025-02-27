#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
int main()
{
    // Adjacency Matrix
    int n, m; // n -> nodes , m -> edges
    cin >> n >> m;
    int adj[n + 1][m + 1]; // Space SC O(N*N)
    for (int i = 0; i < m; ++i)
    {
        int v, u;
        cin >> v >> u;
        adj[v][u] = 1; // case of weight just write the weight instead of 1
        adj[u][v] = 1;
    }
    return 0;
}

int main()
{
    // Adjacency List
    int n, m; // n -> nodes , m -> edges
    cin >> n >> m;
    vector<int> adj[n + 1]; // Space SC O(2E)
    // vector<vector<int>>adj // This can also be used
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // if there is directed graph just take the one edge then the SC (E)
        adj[v].push_back(u);
    }
}

int main()
{
    // For weighted Graph
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; ++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
}
