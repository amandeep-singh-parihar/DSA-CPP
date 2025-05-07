// 63. Unique Paths II
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Revision 1

// Memoization
// TC O(M*N)
// SC O((M-1)*(N-1)) + O(M*N) -> O(M*N) + O(M+N)
int f(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid)
{

    if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) // only condition
        return 0;

    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = f(i - 1, j, dp, obstacleGrid);
    int left = f(i, j - 1, dp, obstacleGrid);

    return dp[i][j] = up + left;
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, dp, obstacleGrid);
}

// Tabulation
// TC O(M*N)
// SC O((M-1)*(N-1)) -> O(M*N)
int _uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    if (obstacleGrid[0][0] == 1)
        return 0;
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 && j == 0)
                dp[0][0] = 1;
            else if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
            {
                int up = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                int left = 0;
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = left + up;
            }
        }
    }
    dp[m - 1][n - 1];
}

// Space Optimization
// TC O(M*N)
// SC O(N-1) -> O(N)
int __uniquePathsWithObstacles(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<int> prev(n, 0), curr(n, 0);

    for (int row = 0; row < m; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            if (row >= 0 && col >= 0 && mat[row][col] == 1)
            {
                curr[col] = 0;
            }
            else if (row == 0 && col == 0)
            {
                curr[col] = 1;
            }
            else
            {
                int up = 0;
                int left = 0;
                if (row > 0)
                    up = prev[col];
                if (col > 0)
                    left = curr[col - 1];
                curr[col] = up + left;
            }
        }
        prev = curr;
    }

    return prev[n - 1];
}

int main()
{
    vector<vector<int>> obstacleGrid = {{0, 0, 0},
                                        {0, 1, 0},
                                        {0, 0, 0}};
    cout << __uniquePathsWithObstacles(obstacleGrid);
    return 0;
}