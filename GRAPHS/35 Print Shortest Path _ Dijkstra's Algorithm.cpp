#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O((n+m)logn)
// SC O(n+m)
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // create the adj list
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); // push the initial in the min heap

    vector<int> dist(n + 1, 1e9); // create a distance vector with all value 10^9
    vector<int> parent(n + 1);    // make a parent vector with index values
    for (int i = 1; i < n + 1; ++i)
        parent[i] = i;

    dist[1] = 0;        // mark the distance of 1(src) as 0
    while (!pq.empty()) // till the min heap is not empty
    {
        int dis = pq.top().first;   
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeW = it.second;
            if (edgeW + dis < dist[adjNode])
            {
                dist[adjNode] = edgeW + dis;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }

    if (dist[n] == 1e9) // if the last node still have 10^9 it means it is not reachable
        return {-1};    // return list contain -1
    vector<int> path;
    int node = n;                // take the last as node
    while (parent[node] != node) // if the parent[node] is not itself
    {
        path.push_back(node); // push the node in the path
        node = parent[node];  // and now go for the parent of that node
    }
    path.push_back(1);                 // push the 1 at the end as the loop break one before
    reverse(path.begin(), path.end()); // reverse the path
    return path;                       // ans

    // return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path.
    // then return
    // path.insert(path.begin(),dist[n]);
    // return path
}

int main()
{
    int n = 5, m = 6;
    vector<vector<int>> edges = {
        {1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};

    vector<int> result = shortestPath(n, m, edges);

    if (result.size() == 1 && result[0] == -1)
    {
        cout << "No path found" << endl;
    }
    else
    {
        cout << "Shortest path: ";
        for (int node : result)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
