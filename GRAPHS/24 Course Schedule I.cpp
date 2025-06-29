#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    // creating the graph
    vector<vector<int>> adj(numCourses);
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }

    vector<int> indegree(numCourses, 0);
    for (int i = 0; i < numCourses; ++i)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    return topo.size() == numCourses;
}

int main()
{

    return 0;
}