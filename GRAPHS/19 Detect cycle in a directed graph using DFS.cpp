// Cycle in a Directed Graph
#include <bits/stdc++.h>
using namespace std;
// r1
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis)
{
    vis[node] = 1;     // mark the node as visited
    pathVis[node] = 1; // mark the node as path visited -> it means it is in the path

    for (auto it : adj[node]) // now for all adjacent node
    {
        if (!vis[it]) // if it is not visited
        {
            if (dfs(it, adj, vis, pathVis)) // call the dfs
                return true;
        }
        else if (pathVis[it]) // if it is visited and also path visited. Results -> cycle
        {
            return true; // return true
        }
    }
    pathVis[node] = 0; // on going back make the nodes as not path visited
    return false;
}

bool isCyclic(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<int> vis(V, 0);      // create the visited vector
    vector<int> pathVis(V, 0);  // create the path visited vector
    for (int i = 0; i < V; ++i) // for all the nodes
    {
        if (!vis[i]) // if the node is not visited
        {
            if (dfs(i, adj, vis, pathVis)) // call for the dfs for node i
                return true;               // if there exist a cycle return true
        }
    }
    return false; // other wise return false
}

int main()
{

    return 0;
}