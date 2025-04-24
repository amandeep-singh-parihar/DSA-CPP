// Unbounded Knapsack
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
// SC O(W) + O(N)
int f(int i, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        return (w / weight[0]) * profit[0];
    }

    if (dp[i][w] != -1)
        return dp[i][w];

    int notTake = f(i - 1, w, profit, weight, dp);
    int take = -1e9;
    if (weight[i] <= w)
    {
        take = profit[i] + f(i, w - weight[i], profit, weight, dp);
    }

    return dp[i][w] = max(notTake, take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return f(n - 1, w, profit, weight, dp);
}

// Tabulation
// TC O(N*W)
// SC O(N*W)
int _unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    for (int i = weight[0]; i <= w; ++i)
    {
        dp[0][i] = (i / weight[0]) * profit[0];
    }

    for (int ind = 1; ind < n; ++ind)
    {
        for (int W = 0; W <= w; ++W)
        {
            int notTake = dp[ind-1][W];
            int take = -1e9;
            if (weight[ind] <= W)
            {
                take = profit[ind] + dp[ind][W-weight[ind]];
            }

            dp[ind][W] = max(notTake, take);
        }
    }
    
    return dp[n-1][w];
}

// Space optimizaion
// TC O(N*W)
// SC O(W+1) == O(1)
int __unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    vector<int>prev(w+1,0),curr(w+1,0);

    for (int i = weight[0]; i <= w; ++i)
    {
        prev[i] = (i / weight[0]) * profit[0];
    }

    for (int ind = 1; ind < n; ++ind)
    {
        for (int W = 0; W <= w; ++W)
        {
            int notTake = prev[W];
            int take = -1e9;
            if (weight[ind] <= W)
            {
                take = profit[ind] + curr[W-weight[ind]];
            }

            curr[W] = max(notTake, take);
        }
        prev = curr;
    }
    
    return prev[w];
}

int main()
{
    vector<int> profit = {5, 11, 13};
    vector<int> weight = {2, 4, 6};
    int w = 10;
    cout << __unboundedKnapsack(3, w, profit, weight);
    return 0;
}