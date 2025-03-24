#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void topoSort(int node, vector<vector<pair<int, int>>> adj, vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        int v = it.first;
        if (!vis[v])
        {
            topoSort(v, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
{
    if (V == 0)
        return {};

    // create the graph TC O(E)
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; ++i)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
        // u->{v,wt}
        //       wt
        // u -----------> v
    }

    // topo sort TC O(V+E)
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; ++i)
    {
        if (!vis[i])
        {
            topoSort(i, adj, vis, st);
        }
    }

    // the distance thing
    vector<int> dist(V, 1e9);
    dist[0] = 0; // according to question the src is 0

    // TC O(V+E)
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (dist[node] + wt < dist[v])
            {
                dist[v] = dist[node] + wt;
            }
        }
    }

    // TC O(V)
    for (int i = 0; i < V; ++i)
        if (dist[i] == 1e9)
            dist[i] = -1;

    return dist;

    // TC O(V+V+E+V+E+E) -> O(3V+3E) -> O(V+E)
    // SC O(V+E)
}

int main()
{

    return 0;
}