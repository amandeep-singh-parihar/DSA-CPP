// 518. Coin Change II
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

#define ull unsigned long long

// Memoization
// TC O(N*amount)
// SC O(N*amount) + O(N)
int f(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
{

    if (i == 0)
    {
        if (amount % coins[0] == 0)
            return 1;
        else
            return 0;
    }

    if (dp[i][amount] != -1)
        return dp[i][amount];

    int notTake = f(i - 1, amount, coins, dp);
    int take = 0;
    if (coins[i] <= amount)
    {
        take = f(i, amount - coins[i], coins, dp);
    }

    return dp[i][amount] = take + notTake;
}
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return f(n - 1, amount, coins, dp);
}

// Tabulation
// TC O(N*amount)
// SC O(N*amount)
int _change(int amount, vector<int> &coins)
{

    int n = coins.size();
    vector<vector<ull>> dp(n, vector<ull>(amount + 1, 0));

    for (int T = 0; T <= amount; ++T)
    {
        if (T % coins[0] == 0)
            dp[0][T] = 1;
        else
            dp[0][T] = 0;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int T = 0; T <= amount; ++T)
        {
            ull notTake = dp[i - 1][T];
            ull take = 0;
            if (coins[i] <= T)
            {
                take = dp[i][T - coins[i]];
            }
            dp[i][T] = take + notTake;
        }
    }
    return dp[n - 1][amount];
}

int main()
{

    return 0;
}