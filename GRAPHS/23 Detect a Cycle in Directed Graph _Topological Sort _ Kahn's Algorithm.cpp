// Cycle in a Directed Graph using Kahn's algorithm
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Topo Sort (BFS)
// TC O(V+E)
// SC O(2N)
bool isCyclic(vector<vector<int>> &adj)
{
    int V = adj.size();
    // calculate the indegree array
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; ++i)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    // if the indegree is zero then push the node in the queue
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
        ++cnt; // everytime pop one element then count how many elements we traverse so far
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    if (cnt == V) // if You process all nodes it means no cycle. Because if there is a cycle then there must be nodes which indegree can never be zero it means we can't process them
    {
        return false;
    }
    return true;
}

int main()
{

    return 0;
}