// 802. Find Eventual Safe States
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
// using kahn's algo
// here we reverse the graph now the graph with 0 incomming edges will be the safe and apply
// the kahn's algo (topo sort using bfs)
// TC O(V+E+VlogV)
// SC O(V+E) + O(V+E)
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<vector<int>> adjRev(V);
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; ++i)
    {
        for (auto it : graph[i])
        {
            adjRev[it].push_back(i); // here instead of using adjRev[i].push_back(it)
            indegree[i]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> safeNodes;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);

        for (auto it : adjRev[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}

int main()
{

    return 0;
}