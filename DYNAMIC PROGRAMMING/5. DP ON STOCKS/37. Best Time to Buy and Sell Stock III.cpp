// 123. Best Time to Buy and Sell Stock III
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Memoization
// TC O(N*2*3)
// SC O(N*2*3) + O(N)

int n;
int f(int idx, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
{

    if (cap == 0)
        return 0;
    if (idx == n)
        return 0;

    if (dp[idx][buy][cap] != -1)
        return dp[idx][buy][cap];

    int profit = INT_MIN;
    if (buy)
    {
        int buyIt = -prices[idx] + f(idx + 1, 0, cap, prices, dp);
        int dontBuyIt = f(idx + 1, 1, cap, prices, dp);
        profit = max(buyIt, dontBuyIt);
    }
    else
    {
        int sellIt = prices[idx] + f(idx + 1, 1, cap - 1, prices, dp);
        int dontSellIt = f(idx + 1, 0, cap, prices, dp);
        profit = max(sellIt, dontSellIt);
    }

    return dp[idx][buy][cap] = profit;
}
int maxProfit(vector<int> &prices)
{
    n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return f(0, 1, 2, prices, dp);
}

// Tabulation
// TC O(N*2*3)
// SC O(N*2*3)
int _maxProfit(vector<int> &prices)
{
    n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // base case -> no need of this because initially the dp is already zero

    // for (int buy = 0; buy <= 1; ++buy)
    // {
    //     for (int cap = 0; cap <= 2; ++cap)
    //     {
    //         dp[n][buy][cap] = 0;
    //     }
    // }

    // the cap in the loop start from 1 as the for cap == 0 the dp is already 0
    for (int idx = n - 1; idx >= 0; --idx)
    {
        for (int buy = 0; buy <= 1; ++buy)
        {
            for (int cap = 1; cap <= 2; ++cap)
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

    return dp[0][1][2];
}

// space optimization
// TC O(N*2*3)
// SC O(2*3) -> O(6) -> O(1)
int __maxProfit(vector<int> &prices)
{
    n = prices.size();
    vector<vector<int>> prev(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

    // the cap in the loop start from 1 as the for cap == 0 the dp is already 0
    for (int idx = n - 1; idx >= 0; --idx)
    {
        for (int buy = 0; buy <= 1; ++buy)
        {
            for (int cap = 1; cap <= 2; ++cap)
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

    return prev[1][2];
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    // prices = {1,2,3,4,5};
    cout << __maxProfit(prices);
    return 0;
}