// Bellman Ford
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
    vector<int> dist(V, 1e8);
    dist[src] = 0;
    for (int i = 0; i < V - 1; ++i) // for V - 1 vertices
    {
        for (auto it : edges) // You will pick it
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Nth relax for the negative edges
    /*
    Detecting Negative Cycles (Nth Iteration):

    If any distance still reduces after this, it means there is a negative weight cycle because we should already have found the shortest path in V-1 terations.
    */
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
        {
            return {-1};
        }
    }

    return dist;
}

int main()
{
    // int V = 4; // Number of vertices
    // vector<vector<int>> edges = {
    //     {0, 1, 1},
    //     {1, 2, -1},
    //     {2, 3, -1},
    //     {3, 1, -1}}; // Graph with a negative cycle

    // int src = 0; // Source vertex

    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 2},
        {1, 3, 5},
        {2, 3, 8},
        {3, 4, 6}};
    int src = 0;

    vector<int> result = bellmanFord(V, edges, src);

    if (result[0] == -1)
    {
        cout << "Negative cycle detected!" << endl;
    }
    else
    {
        cout << "Shortest distances from node " << src << " are:" << endl;
        for (int i = 0; i < V; ++i)
        {
            cout << "Node " << i << ": " << result[i] << endl;
        }
    }

    return 0;
}