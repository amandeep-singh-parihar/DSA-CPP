// 188. Best Time to Buy and Sell Stock IV
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Memoization
// TC O(N*2*K+1)
// SC O(N*2*K+1) + O(N)
int n;
int f(int idx, int buy, int k, vector<int> &prices,
      vector<vector<vector<int>>> &dp)
{
    if (k == 0)
        return 0;
    if (idx == n)
        return 0;

    if (dp[idx][buy][k] != -1)
        return dp[idx][buy][k];

    int profit = -1e9;
    if (buy)
    {
        int buyIt = -prices[idx] + f(idx + 1, 0, k, prices, dp);
        int dontBuyIt = f(idx + 1, 1, k, prices, dp);
        profit = max(buyIt, dontBuyIt);
    }
    else
    {
        int sellIt = prices[idx] + f(idx + 1, 1, k - 1, prices, dp);
        int dontSellIt = f(idx + 1, 0, k, prices, dp);
        profit = max(sellIt, dontSellIt);
    }

    return dp[idx][buy][k] = profit;
}
int maxProfit(int k, vector<int> &prices)
{
    n = prices.size();
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return f(0, 1, k, prices, dp);
}

// Tabulation
// TC O(N*2*K+1)
// SC O(N*2*K+1)
int _maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();

    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for (int idx = n - 1; idx >= 0; --idx)
    {
        for (int buy = 0; buy <= 1; ++buy)
        {
            for (int cap = 1; cap <= k; ++cap)
            {
                int profit = -1e9;
                if (buy)
                {
                    int buyIt = -prices[idx] + dp[idx + 1][0][cap];
                    int dontBuyIt = dp[idx + 1][1][cap];
                    profit = max(buyIt, dontBuyIt);
                }
                else
                {
                    int sellIt = prices[idx] + dp[idx + 1][1][cap - 1];
                    int dontSellIt = dp[idx + 1][0][cap];
                    profit = max(sellIt, dontSellIt);
                }
                dp[idx][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][k];
}

// space optimization
// TC O(N*2*K+1)
// SC O(2*K+1) -> O(K)
int __maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> prev(2, vector<int>(k + 1, 0)),
        curr(2, vector<int>(k + 1, 0));

    for (int idx = n - 1; idx >= 0; --idx)
    {
        for (int buy = 0; buy <= 1; ++buy)
        {
            for (int cap = 1; cap <= k; ++cap)
            {
                int profit = -1e9;
                if (buy)
                {
                    int buyIt = -prices[idx] + prev[0][cap];
                    int dontBuyIt = prev[1][cap];
                    profit = max(buyIt, dontBuyIt);
                }
                else
                {
                    int sellIt = prices[idx] + prev[1][cap - 1];
                    int dontSellIt = prev[0][cap];
                    profit = max(sellIt, dontSellIt);
                }
                curr[buy][cap] = profit;
            }
        }
        prev = curr;
    }
    return prev[1][k];
}

int main()
{
    int k = 2;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    cout << __maxProfit(k, prices);
    return 0;
}