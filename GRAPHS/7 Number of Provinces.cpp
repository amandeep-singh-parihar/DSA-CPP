// 547. Number of Provinces
#include <bits/stdc++.h>
using namespace std;
// r1
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(N) + O(V + 2E)
// SC O(N) + O(N)
void dfs(int node, vector<vector<int>> &adjLs, vector<int> &vis)
{
    vis[node] = 1;

    for (auto it : adjLs[node])
    {
        if (!vis[it])
        {
            dfs(it, adjLs, vis);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int V = isConnected.size();
    vector<vector<int>> adjLs(V);
    for (int i = 0; i < V; ++i) // for creating the adjacency list
    {
        for (int j = 0; j < V; ++j)
        {
            if (isConnected[i][j] == 1 && i != j)
            {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    // The logic behind it is that as we call the dfs, it mark the nodes as visited ,only those
    // which are not connected to the graph have the nodes as marked 0 so in this way the if condition
    // below only runs for the number of disconnected graph.

    vector<int> vis(V, 0); // now we take the visited array
    int cnt = 0;           // take the count as 0
    for (int i = 0; i < V; ++i)
    {
        if (vis[i] == 0) // if the node is not visited
        {
            ++cnt;              // increase the count
            dfs(i, adjLs, vis); // make the dfs call
        }
    }
    return cnt; // ans the count
}

int main()
{
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};

    cout << "Number of Provinces: " << findCircleNum(isConnected) << "\n";
    return 0;
}