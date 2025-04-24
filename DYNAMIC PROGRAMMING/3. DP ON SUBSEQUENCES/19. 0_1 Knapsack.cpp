// DP 19. 0/1 Knapsack
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Memoization
// TC O(N*W)
// SC O(N*W) + O(N)
int f(int i, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{

    if (i == 0)
    {
        if (wt[0] <= W)
            return val[0];
        return 0;
    }

    if (dp[i][W] != -1)
        return dp[i][W];

    int notTake = f(i - 1, W, val, wt, dp);
    int take = -1e9;
    if (wt[i] <= W)
    {
        take = val[i] + f(i - 1, W - wt[i], val, wt, dp); // take the value and reduce the weight
    }

    return dp[i][W] = max(notTake, take);
}
int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size(); // any one size even i also take wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return f(n - 1, W, val, wt, dp);
}

// Tabulation
// TC O(N*W)
// SC O(N*W)
int _knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size(); // any one size even i also take wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int i = wt[0]; i <= W; ++i)
    {
        dp[0][i] = val[0];
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= W; ++j)
        {
            int notTake = dp[i - 1][j];
            int take = -1e9;
            if (wt[i] <= j)
            {
                take = val[i] + dp[i - 1][j - wt[i]];
            }

            dp[i][j] = max(notTake, take);
        }
    }

    return dp[n - 1][W];
}

int main()
{
    int W = 4;
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    cout << _knapsack(W, val, wt);
    return 0;
}