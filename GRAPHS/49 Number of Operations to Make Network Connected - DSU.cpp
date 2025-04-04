// 1319. Number of Operations to Make Network Connected
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class DisjointSet
{
public:
    vector<int> size, parent;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int makeConnected(int n, vector<vector<int>> &connections)
{
    DisjointSet ds(n);
    int cntExtras = 0;
    for (auto it : connections)
    {
        int u = it[0];
        int v = it[1];
        if (ds.findUPar(u) == ds.findUPar(v))
            ++cntExtras;
        else
            ds.unionBySize(u, v);
    }

    int connected_cmp = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ds.parent[i] == i)
        {
            ++connected_cmp;
        }
    }
    if (connected_cmp - 1 <= cntExtras)
        return connected_cmp - 1;

    return -1;
}

int main()
{

    return 0;
}