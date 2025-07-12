#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class DisJointSet
{
    vector<int> size, parent;

public:
    DisJointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; ++i)
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
        int ulpU = findUPar(u);
        int ulpV = findUPar(v);
        if (ulpU == ulpV)
            return;

        if (size[ulpU] < size[ulpV])
        {
            parent[ulpU] = ulpV;
            size[ulpV] += size[ulpU];
        }
        else
        {
            parent[ulpV] = ulpU;
            size[ulpU] += size[ulpV];
        }
    }
};
int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    int maxRow = 0;
    int maxCol = 0;
    for (auto it : stones)
    {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    DisJointSet ds(maxRow + maxCol + 1);
    unordered_map<int, bool> usedNodes;
    for (auto it : stones)
    {
        int row = it[0];
        int col = it[1] + maxRow + 1;
        ds.unionBySize(row, col);
        usedNodes[row] = true;
        usedNodes[col] = true;
    }

    int compo = 0;
    for (auto it : usedNodes)
    {
        if (ds.findUPar(it.first) == it.first)
            ++compo;
    }
    return n - compo;
}

int main()
{

    return 0;
}