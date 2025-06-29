// 122. Best Time to Buy and Sell Stock II
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Memoization
// TC O(N*2)
// SC O(N*2) + O(N)

int n;
int f(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (idx == n)
        return 0;

    if (dp[idx][buy] != -1)
        return dp[idx][buy];

    int profit = -1e9;
    if (buy)
    {
        int buyIt = -prices[idx] + f(idx + 1, 0, prices, dp);
        int dontBuyIt = f(idx + 1, 1, prices, dp);
        profit = max(buyIt, dontBuyIt);
    }
    else
    {
        int sellIt = prices[idx] + f(idx + 1, 1, prices, dp);
        int dontSellIt = f(idx + 1, 0, prices, dp);
        profit = max(sellIt, dontSellIt);
    }
    return dp[idx][buy] = profit;
}

int maxProfit(vector<int> &prices)
{
    n = prices.size();
    // dp[n][2] as n go from 0 to n
    // 2 because buy or not 0,1
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, prices, dp);
}

// Tabulation
// TC O(N*2)
// SC O(N*2)
int _maxProfit(vector<int> &prices)
{
    n = prices.size();
    // dp[n][2] as n go from 0 to n
    // 2 because buy or not 0,1
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    // base case
    dp[n][0] = dp[n][1] = 0;
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
                int sellIt = prices[idx] + dp[idx + 1][1];
                int dontSellIt = dp[idx + 1][0];
                profit = max(sellIt, dontSellIt);
            }
            dp[idx][buy] = profit;
        }
    }
    return dp[0][1];
}

// Space optimization
// TC O(N*2)
// SC O(2) -> O(1)
int __maxProfit(vector<int> &prices)
{
    n = prices.size();
    // dp[n][2] as n go from 0 to n
    // 2 because buy or not 0,1
    vector<int> prev(2, 0), curr(2, 0);
    // base case
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
                int sellIt = prices[idx] + prev[1];
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
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // prices = {1,2,3,4,5};
    cout << __maxProfit(prices);
    return 0;
}