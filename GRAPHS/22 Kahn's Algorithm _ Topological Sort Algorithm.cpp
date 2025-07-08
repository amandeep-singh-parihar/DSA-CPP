// Topological sort using bfs
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Topo Sort with BFS
// TC O(V+E)
// SC O(V+E)
vector<int> topologicalSort(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<int> indegree(V, 0); // create a vector of indegree
    for (int i = 0; i < V; ++i) // travers the nodes
    {
        for (auto it : adj[i]) // traverse the adjacent nodes
        {
            indegree[it]++; // increase the indegree of them as they are adjacent nodes of someone
        }
    }

    queue<int> q; // create a queue
    for (int i = 0; i < V; ++i)
    {
        if (indegree[i] == 0) // if the indegree is 0 push the node in the queue, DAG always have minimum of 1 node having indegree 0
            q.push(i);
    }

    vector<int> topo;  // for storing the ans
    while (!q.empty()) // till the q is not empty
    {
        int node = q.front(); // take the front element
        q.pop();              // pop it from the q
        topo.push_back(node); // push it in the topo (ans)

        for (auto it : adj[node]) // now traverse the all adjacent nodes of the node(pop from the q)
        {
            indegree[it]--;        // decrease its indegree
            if (indegree[it] == 0) // if the indegree of it is 0
                q.push(it);        // push it in the q
        }
    }
    return topo;
}

int main()
{

    return 0;
}