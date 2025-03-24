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
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeW = it.second;

            if (edgeW + dis < dist[adjNode])
            {
                if (dist[adjNode] != 1e9)
                {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = edgeW + dis;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{

    return 0;
}