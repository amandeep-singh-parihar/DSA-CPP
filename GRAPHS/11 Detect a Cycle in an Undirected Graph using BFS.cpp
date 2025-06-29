// Undirected Graph Cycle
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(N + 2E) + O(N)
// SC O(N)
bool detect(int src, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[src] = 1;            // mark the source as visited
    queue<pair<int, int>> q; // queue {node,parent}
    q.push({src, -1});       // intially {node,-1}
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;

        for (auto adjacentNode : adj[node])
        {
            if (!vis[adjacentNode]) // if the adjacent node is not marked yet
            {
                vis[adjacentNode] = 1;        // mark it 1
                q.push({adjacentNode, node}); // and push it in the queue
            }
            else if (parent != adjacentNode) // if the adjacent node is marked as 1 so check if it is parent if it is parent then no problem , but if it is not parent then how it is marked already -> cycle
            {
                return true;
            }
        }
    }
    return false;
}
bool isCycle(vector<vector<int>> &adj)
{
    int V = adj.size();    // visited array
    vector<int> vis(V, 0); // mark all as 0
    for (int i = 0; i < V; ++i)
    {
        if (!vis[i]) // this is for the disconnected graph
        {
            if (detect(i, adj, vis)) // if any cycle return true
                return true;
        }
    }
    return false; // else return false;
}

int main()
{

    return 0;
}