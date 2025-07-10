#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O((V+E)×logV)
// SC O(V+E)
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    int V = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9); // created a dist array with initilize value as 10^9

    dist[src] = 0;      // mark the source as 0
    pq.push({0, src});  // push in the min-heap with {dist=0,src}
    while (!pq.empty()) // till the min-heap is not empty
    {
        int dis = pq.top().first;   // take the distance (dis) from the min-heap
        int node = pq.top().second; // take the node from the min-heap
        pq.pop();                   // pop it

        for (auto it : adj[node]) // for all the adjacent nodes
        {
            int adjNode = it.first;     // take the adjacent node
            int edgeWeight = it.second; // take the edge weight

            if (edgeWeight + dis < dist[adjNode]) // relax(update the distance)
            {
                dist[adjNode] = edgeWeight + dis;
                pq.push({dist[adjNode], adjNode}); // push the updated distance and the adjacent node
            }
        }
    }
    return dist; // return the distance array
}

int main()
{

    return 0;
}