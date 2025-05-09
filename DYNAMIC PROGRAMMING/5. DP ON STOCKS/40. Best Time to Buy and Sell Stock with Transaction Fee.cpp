// 714. Best Time to Buy and Sell Stock with Transaction Fee
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Memoization
// TC
// SC
int n;
int f(int idx, int buy, int fee, vector<int> &prices,
      vector<vector<int>> &dp)
{
    if (idx == n)
        return 0;

    if (dp[idx][buy] != -1)
        return dp[idx][buy];

    int profit = -1e9;
    if (buy)
    {
        int buyIt = -prices[idx] + f(idx + 1, 0, fee, prices, dp);
        int dontBuyIt = f(idx + 1, 1, fee, prices, dp);
        profit = max(buyIt, dontBuyIt);
    }
    else
    {
        int sellIt = prices[idx] - fee + f(idx + 1, 1, fee, prices, dp);
        int dontSellIt = f(idx + 1, 0, fee, prices, dp);
        profit = max(sellIt, dontSellIt);
    }

    return dp[idx][buy] = profit;
}
int maxProfit(vector<int> &prices, int fee)
{
    n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, fee, prices, dp);
}

// Tabulation
// TC ()
// SC ()
int _maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int idx = n - 1; idx >= 0; --idx)
    {
        for (int buy = 0; buy <= 1; ++buy)
        {
            int profit = -1e9;
            if (buy)
            {
                int buyIt = -prices[idx] + dp[idx + 1][0];
                int dontBuyIt = dp[idx + 1][1];
                profit = max(buyIt, dontBuyIt);
            }
            else
            {
                int sellIt = prices[idx] - fee + dp[idx + 1][1];
                int dontSellIt = dp[idx + 1][0];
                profit = max(sellIt, dontSellIt);
            }
            dp[idx][buy] = profit;
        }
    }
    return dp[0][1];
}

// Space optimization
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<int> prev(2, 0), curr(2, 0);
    for (int idx = n - 1; idx >= 0; --idx)
    {
        for (int buy = 0; buy <= 1; ++buy)
        {
            int profit = -1e9;
            if (buy)
            {
                int buyIt = -prices[idx] + prev[0];
                int dontBuyIt = prev[1];
                profit = max(buyIt, dontBuyIt);
            }
            else
            {
                int sellIt = prices[idx] - fee + prev[1];
                int dontSellIt = prev[0];
                profit = max(sellIt, dontSellIt);
            }
            curr[buy] = profit;
        }
        prev = curr;
    }
    return prev[1];
}

int main()
{

    return 0;
}