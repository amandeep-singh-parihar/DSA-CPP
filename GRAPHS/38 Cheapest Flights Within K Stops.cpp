// 787. Cheapest Flights Within K Stops
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(E) = O(flights.size())
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                      int k)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    vector<int> dist(n, 1e9);

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if (stops > k)
            continue;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgW = it.second;

            if (edgW + cost < dist[adjNode] && stops <= k)
            {
                dist[adjNode] = edgW + cost;
                q.push({stops + 1, {adjNode, dist[adjNode]}});
            }
        }
    }

    if (dist[dst] == 1e9)
        return -1;
    return dist[dst];
}

int main()
{

    return 0;
}