// Cycle in a Directed Graph using Kahn's algorithm
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(V+E)
// SC O(2N)
bool isCyclic(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; ++i)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // no need to store the order
    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ++cnt;
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    if (cnt == V)
        return false;
    return true;
}

int main()
{

    return 0;
}