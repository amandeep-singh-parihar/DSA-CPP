// 2685. Count the Number of Complete Components
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void bfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &nodeCnt, int &edgeCnt)
{

    queue<int> q;
    q.push(node);
    vis[node] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ++nodeCnt;
        edgeCnt += adj[curr].size();
        for (auto ngbr : adj[curr])
        {
            if (!vis[ngbr])
            {
                vis[ngbr] = 1;
                q.push(ngbr);
            }
        }
    }
}

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &nodeCnt, int &edgeCnt)
{
    vis[node] = 1;
    ++nodeCnt;
    edgeCnt += adj[node].size();
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, nodeCnt, edgeCnt);
        }
    }
}

int countCompleteComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n, 0);
    int completeCmt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            int nodeCnt = 0, edgeCnt = 0;
            dfs(i, adj, vis, nodeCnt, edgeCnt);

            if (edgeCnt / 2 == (nodeCnt * (nodeCnt - 1)) / 2)
            {
                ++completeCmt;
            }
        }
    }
    return completeCmt;
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {4, 5}};

    cout << "Complete Components: " << countCompleteComponents(n, edges) << endl;

    return 0;
}