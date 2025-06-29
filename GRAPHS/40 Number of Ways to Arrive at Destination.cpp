// 1976. Number of Ways to Arrive at Destination
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

#define ll long long

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                   greater<pair<ll, int>>>
        pq;
    pq.push({0, 0});
    vector<ll> dist(n, 1e18), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    int mod = (int)(1e9 + 7);
    while (!pq.empty())
    {
        ll dis = pq.top().first;
        ll node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            ll adjNode = it.first;
            ll edgW = it.second;
            if (dis + edgW < dist[adjNode])
            {
                dist[adjNode] = dis + edgW;
                pq.push({dist[adjNode], adjNode});
                ways[adjNode] = ways[node];
            }
            else if (dis + edgW == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }
    return ways[n - 1] % mod;
}

int main()
{
    int n = 7;
    vector<vector<int>> roads = {
        {0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    cout << "Number of ways to reach node " << n - 1 << ": " << countPaths(n, roads) << endl;

    return 0;
}
