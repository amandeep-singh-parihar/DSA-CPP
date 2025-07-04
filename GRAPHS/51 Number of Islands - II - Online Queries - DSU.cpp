// Number Of Islands II
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
    vector<int> size, parent;

public:
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

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
{
    DisjointSet ds(n * m);
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    vector<int> ans;
    for (auto it : operators)
    {
        int row = it[0];
        int col = it[1];

        if (vis[row][col] == 1)
        {
            ans.push_back(cnt);
            continue;
        }

        vis[row][col] = 1;
        ++cnt;
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; ++i)
        {
            int adjr = row + delRow[i];
            int adjc = col + delCol[i];
            if (adjr >= 0 && adjr < n && adjc >= 0 && adjc < m && vis[adjr][adjc] == 1)
            {
                int nodeNo = row * m + col;
                int adjNodeNo = adjr * m + adjc;
                if (ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo))
                {
                    --cnt;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main()
{
    int n = 4, m = 5;
    vector<vector<int>> positions = {{1, 1}, {0, 1}, {3, 3}, {3, 4}};
    // vector<vector<int>> positions = {{0,0},{1,1},{2,2},{3,3}};

    vector<int> result = numOfIslands(n, m, positions);

    for (int count : result)
    {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}