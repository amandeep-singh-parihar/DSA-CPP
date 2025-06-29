// 322. Coin Change
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Memoization
// TC O(N*amount)
// SC O(N*amount) + O(N)
int f(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (amount % coins[i] == 0)
            return amount / coins[i];
        else
            return 1e9;
    }

    if (dp[i][amount] != -1)
        return dp[i][amount];

    int notTake = f(i - 1, amount, coins, dp);
    int take = 1e9;
    if (coins[i] <= amount)
    {
        take = 1 + f(i, amount - coins[i], coins, dp);
    }

    return dp[i][amount] = min(notTake, take);
}

int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = f(n - 1, amount, coins, dp);
    return ans >= 1e9 ? -1 : ans;
}

// Tabulation
// TC O(N*amount)
// SC O(N*amount)
int _coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;

    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    // base case
    for (int T = 0; T <= amount; ++T)
    {
        if (T % coins[0] == 0)
            dp[0][T] = T / coins[0];
        else
            dp[0][T] = 1e9;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int T = 0; T <= amount; ++T)
        {

            int notTake = dp[i - 1][T];
            int take = 1e9;
            if (coins[i] <= T)
            {
                take = 1 + dp[i][T - coins[i]];
            }
            dp[i][T] = min(notTake, take);
        }
    }
    int ans = dp[n - 1][amount];
    return (ans >= 1e9) ? -1 : ans;
}

// Space optimization
// TC O(N*amount)
// SC O(amount+1) near about O(1)
int __coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;

    int n = coins.size();

    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
    // vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    // base case
    for (int T = 0; T <= amount; ++T)
    {
        if (T % coins[0] == 0)
            prev[T] = T / coins[0];
        else
            prev[T] = 1e9;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int T = 0; T <= amount; ++T)
        {

            int notTake = prev[T];
            int take = 1e9;
            if (coins[i] <= T)
            {
                take = 1 + curr[T - coins[i]];
            }
            curr[T] = min(notTake, take);
        }
        prev = curr;
    }
    int ans = prev[amount];
    return (ans >= 1e9) ? -1 : ans;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << __coinChange(coins, amount);
    return 0;
}