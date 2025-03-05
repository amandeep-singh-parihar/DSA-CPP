// Find the number of islands
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void dfs(int row, int col, int n, int m, int delRow[], int delCol[], vector<vector<char>> &grid, vector<vector<int>> &vis)
{

    vis[row][col] = 1;

    for (int i = 0; i < 8; ++i)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
        {
            dfs(nrow, ncol, n, m, delRow, delCol, grid, vis);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    if (grid.empty())
        return 0;

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0)); // initially all zeros
    int delRow[8] = {-1, -1, -1, 0, 1, 1, 1, 0};   // for all the 8 directions
    int delCol[8] = {-1, 0, 1, 1, 1, 0, -1, -1};   // for all the 8 directions
    int cnt = 0;                                   // let the count be 0
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!vis[i][j] && grid[i][j] == '1') // if the element is not visited and grid[i][j]=='1'
            {
                ++cnt;
                dfs(i, j, n, m, delRow, delCol, grid, vis);
            }
        }
    }
    return cnt;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    cout << "Number of islands: " << numIslands(grid) << endl;

    return 0;
}