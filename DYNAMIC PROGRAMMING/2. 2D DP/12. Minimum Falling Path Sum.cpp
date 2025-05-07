// 931. Minimum Falling Path Sum
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Revision 1

// Memoization (TLE on leetcode)
// O(N*N)
// O(N*N) + O(N)
int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp, int n)
{
    // Base case 1
    if (j < 0 || j > n - 1) // <- this condition must be before the below one because if this don't come first then might j can take values like -2(col) then the below condition calculate for matrix[0][-2] which is heap buffer overflow. So this condition must come before the Base case 2
        return INT_MAX;

    // Base case 2
    if (i == 0)
        return matrix[0][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = f(i - 1, j, matrix, dp, n);
    int diL = f(i - 1, j - 1, matrix, dp, n);
    int diR = f(i - 1, j + 1, matrix, dp, n);

    return dp[i][j] = matrix[i][j] + min(up, min(diL, diR));
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int res = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int j = 0; j < n; ++j)
    {
        res = min(res, f(n - 1, j, matrix, dp, n));
    }
    return res;
}

// Tabulation
// TC O(N*N) + O(N)
// SC O(N*N)
int _minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int res = INT_MAX;
    // Base case
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int j = 0; j < n; ++j)
    {
        dp[0][j] = matrix[0][j];
    }

    // must be reverse of memoization
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int up = dp[i - 1][j];
            int diL = INT_MAX;
            if (j - 1 >= 0)
                diL = dp[i - 1][j - 1];
            int diR = INT_MAX;
            if (j + 1 < n)
                diR = dp[i - 1][j + 1];
            dp[i][j] = matrix[i][j] + min(up, min(diL, diR));
        }
    }

    int ans = INT_MAX;
    for (int j = 0; j < n; ++j)
    {
        ans = min(ans, dp[n - 1][j]);
    }
    return ans;
}

// Space optimization
// TC O(N*N) + O(N)
// SC O(N)
int __minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int res = INT_MAX;
    vector<int> prev(n, 0), curr(n, 0);
    // Base case
    for (int j = 0; j < n; ++j)
    {
        prev[j] = matrix[0][j];
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int up = prev[j];
            int diL = INT_MAX;
            if (j - 1 >= 0)
                diL = prev[j - 1];
            int diR = INT_MAX;
            if (j + 1 < n)
                diR = prev[j + 1];
            curr[j] = matrix[i][j] + min(up, min(diL, diR));
        }
        prev = curr;
    }

    int ans = prev[0];
    for (int j = 1; j < n; ++j)
    {
        ans = min(ans, prev[j]);
    }
    return ans;
}

int main()
{

    return 0;
}