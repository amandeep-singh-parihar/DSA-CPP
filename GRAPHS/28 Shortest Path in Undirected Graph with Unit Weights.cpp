#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(V+E)
// SC O(V)

vector<int> shortestPath(vector<vector<int>> &adj, int src)
{
    int V = adj.size();       // take the number of vertices
    vector<int> dist(V, 1e9); // make a distance vector of size V
                              // initilize the each value in the distance vector as 10^9

    dist[src] = 0;     // mark the source distance as 0
    queue<int> q;      // make the q
    q.push(src);       // push the source in the q
    while (!q.empty()) // till the q is not empty
    {
        int node = q.front(); // take the node from the q
        q.pop();              // pop it

        for (auto it : adj[node]) // now check all the adjacent nodes of it
        {
            if (dist[node] + 1 < dist[it]) // if the distance of node + 1 is less than distance of adjacent node
            {
                dist[it] = dist[node] + 1; // mark the distance of that adjacent node as distance(old) + 1
                q.push(it);                // push the adjacent node in the queue
            }
        }
    }
    vector<int> ans(V, -1); // make a vector of size V having -1 initially
    for (int i = 0; i < V; ++i)
    {
        if (dist[i] != 1e9) // if the distance of i is not 10^9
        {
            ans[i] = dist[i]; // put the distance of i in the and
        }
    }
    return ans; // return the ans
}

int main()
{

    return 0;
}