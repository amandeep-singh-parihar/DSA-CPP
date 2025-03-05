// 1020. Number of Enclaves
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void dfs(int row, int col, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis, int delRow[], int delCol[])
{
    vis[row][col] = 1;
    for (int i = 0; i < 4; ++i)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if (!vis[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, n, m, grid, vis, delRow, delCol);
        }
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    // Row Traversal
    for (int j = 0; j < m; ++j)
    {
        // First Row
        if (!vis[0][j] && grid[0][j] == 1)
        {
            dfs(0, j, n, m, grid, vis, delRow, delCol);
        }

        // Last Row
        if (!vis[n - 1][j] && grid[n - 1][j] == 1)
        {
            dfs(n - 1, j, n, m, grid, vis, delRow, delCol);
        }
    }

    // Col Traversal
    for (int i = 0; i < n; ++i)
    {
        // First Col
        if (!vis[i][0] && grid[i][0] == 1)
        {
            dfs(i, 0, n, m, grid, vis, delRow, delCol);
        }

        // Last Col
        if (!vis[i][m - 1] && grid[i][m - 1] == 1)
        {
            dfs(i, m - 1, n, m, grid, vis, delRow, delCol);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                ++cnt;
            }
        }
    }
    return cnt;
}

int main()
{

    // Input
    /*
    4 4
    0 0 0 0
    1 0 1 0
    0 1 1 0
    0 0 0 0
    */

    // Output -> 3

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    // Input grid
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }

    // Compute the number of enclaves
    int result = numEnclaves(grid);

    // Output the result
    cout << "Result : " << result << endl;

    return 0;
}
