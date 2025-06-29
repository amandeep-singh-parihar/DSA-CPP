// 827. Making A Large Island
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

int largestIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    DisjointSet ds(n * n);
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            if (grid[row][col] == 0)
                continue;
            for (int ind = 0; ind < 4; ++ind)
            {
                int newr = row + delRow[ind];
                int newc = col + delCol[ind];
                if (newr >= 0 && newr < n && newc >= 0 && newc < n &&
                    grid[newr][newc] == 1)
                {
                    int nodeNo = row * n + col;
                    int adjNodeNo = newr * n + newc;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }

    int maxi = 0;
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            if (grid[row][col] == 1)
                continue;
            set<int> components;
            for (int ind = 0; ind < 4; ++ind)
            {
                int newr = row + delRow[ind];
                int newc = col + delCol[ind];
                if (newr >= 0 && newr < n && newc >= 0 && newc < n &&
                    grid[newr][newc] == 1)
                {
                    components.insert(ds.findUPar(newr * n + newc));
                }
            }
            int sizeT = 0;
            for (auto it : components)
            {
                sizeT += ds.size[it];
            }
            maxi = max(maxi, sizeT + 1);
        }
    }
    for (int cellNo = 0; cellNo < n * n; ++cellNo)
    {
        maxi = max(maxi, ds.size[ds.findUPar(cellNo)]);
    }
    return maxi;
}

int main()
{

    return 0;
}