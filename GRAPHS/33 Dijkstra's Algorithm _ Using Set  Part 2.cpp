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
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);

    st.insert({0, src});
    while (!st.empty())
    {
        auto it = *(st.begin()); // the first element in the set
        int node = it.second;    // take the node
        int dis = it.first;      // take the dis
        st.erase(it);            // erase it from the set

        for (auto it : adj[node]) // traverse the adj
        {
            int adjNode = it.first; // take the adjNode
            int edgeW = it.second;  // take the edgeW

            if (edgeW + dis < dist[adjNode]) // if You got any smaller distance
            {
                if (dist[adjNode] != 1e9) // check if the dist[adjNode] != 1e9 it means someone already touched it so erase the old dist and that node from the set
                {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = edgeW + dis;         // update the dist[adjNode]
                st.insert({dist[adjNode], adjNode}); // insert it in the set
            }
        }
    }
    return dist;
}

int main()
{

    return 0;
}