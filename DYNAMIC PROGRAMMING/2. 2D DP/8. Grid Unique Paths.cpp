// 62. Unique Paths
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
// SC O((M-1)*(N-1)) + O(M*N)
int f(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = f(i - 1, j, dp);
    int left = f(i, j - 1, dp);
    return dp[i][j] = left + up;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, dp);
}

// Tabulation
// TC O(M*N)
// SC O((M-1)*(N-1))
int _uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 && j == 0)
                dp[0][0] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = left + up;
            }
        }
    }
    return dp[m - 1][n - 1];
}

// space optimization part pending ((CP)not required more but if you want)
// TC O(M*N)
// SC O(N+N) -> O(2N) -> O(N)
int __uniquePaths(int m, int n)
{
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    vector<int> prev(n, 0);
    for (int i = 0; i < m; ++i)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 && j == 0)
                curr[0] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = left + up;
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}

int main()
{
    cout << __uniquePaths(3, 3);
    return 0;
}