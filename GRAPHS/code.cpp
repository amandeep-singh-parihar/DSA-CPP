#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int> bfsOfGraph(vector<vector<int>> &adj)
{
    int n = adj.size();    // total number of nodex
    vector<int> vis(n, 0); // visited vector of size n initilize with 0
    vis[1] = 1;            // first marked as visited;
    queue<int> q;
    q.push(1);
    vector<int> bfs;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        bfs.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

void dfs(int node, vector<vector<int>> &adj, vector<int> &res, vector<int> &vis)
{
    vis[node] = 1;
    res.push_back(node);

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, res, vis);
        }
    }
}

vector<int> dfsOfGraph(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<int> res;
    vector<int> vis(V, 0);
    // vector<int>ls;
    int startNode = 1;
    dfs(startNode, adj, res, vis);
    return res;
}

bool __dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis)
{

    vis[node] = 1;

    // check of the ngbr;
    for (auto ngbr : adj[node])
    {
        if (!vis[ngbr])
        {
            if (__dfs(ngbr, node, adj, vis))
                return true;
        }
        else if (ngbr != node)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, 0);
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            if (__dfs(i, -1, adj, vis))
                return true;
        }
    }
    return false;
}

bool ___dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj)
{
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (___dfs(it, vis, pathVis, adj))
                return true;
        }
        else if (pathVis[it])
        {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}

bool isCyclic(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    for (int i = 0; i < V; ++i)
    {
        if (!vis[i])
        {
            if (___dfs(i, vis, pathVis, adj))
                return true;
        }
    }
    return false;
}

int main()
{

    //     0
    //    / \
    //   1   2
    //  / \  / \
    // 3   4 5  6

    vector<vector<int>> adj = {
        {},
        {2, 6},
        {1, 3, 4},
        {2},
        {2, 5},
        {4, 8},
        {1, 7, 9},
        {6, 8},
        {5, 7},
        {6}};

    vector<int> dfs = dfsOfGraph(adj);

    // vector<int> bfs = bfsOfGraph(adj);

    // cout << "BFS Traversal: ";
    for (int node : dfs)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}