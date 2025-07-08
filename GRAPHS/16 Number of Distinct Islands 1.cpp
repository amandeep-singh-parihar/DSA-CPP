// Number of Distinct Islands
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int delRow[4] = {-1, 0, 1, 0};
int delCol[4] = {0, 1, 0, -1};
int n, m;
void dfs(int row, int col, int baseRow, int baseCol, vector<vector<int>> &vis,
         vector<vector<int>> &grid, vector<pair<int, int>> &vec)
{
    vis[row][col] = 1;
    vec.push_back({row - baseRow, col - baseCol});

    for (int i = 0; i < 4; ++i)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, baseRow, baseCol, vis, grid, vec);
        }
    }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    n = grid.size();    // row
    m = grid[0].size(); // col
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> vec;
                dfs(i, j, i, j, vis, grid, vec);
                st.insert(vec);
            }
        }
    }
    return st.size();
}

int main()
{

    return 0;
}