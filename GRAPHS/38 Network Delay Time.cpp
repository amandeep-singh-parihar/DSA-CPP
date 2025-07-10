// 743. Network Delay Time
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{

    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto it : times)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, k}); // {time,node}
    vector<int> dist(n + 1, 1e9);
    dist[k] = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int time = it.first;
        int node = it.second;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgW = it.second;
            if (edgW + time < dist[adjNode])
            {
                dist[adjNode] = edgW + time;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    int maxTime = INT_MIN;

    for (int i = 1; i < n + 1; ++i)
    {
        if (dist[i] == 1e9)
            return -1;
        else
        {
            maxTime = max(maxTime, dist[i]);
        }
    }
    return maxTime;
}

int main()
{
    vector<vector<int>> times = {
        {1, 2, 3},
        {1, 3, 5},
        {2, 3, 1},
        {2, 4, 6},
        {3, 4, 2},
        {4, 5, 1},
        {5, 6, 7},
        {1, 6, 50}}; // Test case

    int n = 6; // Number of nodes
    int k = 1; // Starting node

    int result = networkDelayTime(times, n, k);
    cout << "Network Delay Time: " << result << "\n";

    return 0;
}