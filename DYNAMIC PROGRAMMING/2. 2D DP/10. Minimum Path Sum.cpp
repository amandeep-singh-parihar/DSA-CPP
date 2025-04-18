// 64. Minimum Path Sum
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Memoization
// TC O(M*N)
// SC O(M*N) + (M-1) + (N-1)
int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return INT_MAX;

    if (i == 0 && j == 0)
        return grid[0][0];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = f(i - 1, j, grid, dp);
    int left = f(i, j - 1, grid, dp);

    return dp[i][j] = grid[i][j] + min(up, left);
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, grid, dp);
}

// Tabulation
// TC O(M*N)
// SC O(M*N)
int _minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[0][0];
            else
            {
                int up = INT_MAX;
                if (i > 0)
                    up = dp[i - 1][j];
                int left = INT_MAX;
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    cout << _minPathSum(grid);
    return 0;
}