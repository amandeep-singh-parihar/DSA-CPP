#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Kahn's Algorithm
// TC O(V+E)
// SC O(V+E)
// very simple appraoch
// put the logic of kahn's algo
// if there is any cycle then it is not possible to take any course before any
// so after applying the algo if there cnt == numCourses it means all the nodes traversed
// it means the person can take all the courses
// but if it not happen then it means there is a cycle
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