// DP 17. Counts Subsets with Sum K | Dp on Subsequences
// Count Subsets with Sum K
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Memoization
// TC O(N*K)
// SC O(N*K) + O(N)
int f(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    // below is only for if the array contain greater than 0
    // if (k == 0)
    //     return 1;
    // if (i == 0)
    // {
    //     return k == arr[0];
    // }

    // if it contain 0 also
    if (i == 0)
    {
        if (k == 0 && arr[0] == 0)
            return 2;
        if (k == 0 || k == arr[0])
            return 1;
        return 0;
    }

    if (dp[i][k] != -1)
        return dp[i][k];

    int notPick = f(i - 1, k, arr, dp);
    int pick = 0;
    if (arr[i] <= k)
    {
        pick = f(i - 1, k - arr[i], arr, dp);
    }

    return dp[i][k] = notPick + pick;
}

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, arr, dp);
}

// Memoization
// TC O(N*K)
// SC O(N*K)
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    // if the array doesn't contain zeros (0)
    // for (int i = 0; i < n; ++i)
    //     dp[i][0] = 1;
    // if (arr[0] <= k)
    //     dp[0][arr[0]] = 1;

    // if the array contain zeros
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (arr[0] != 0 && arr[0] <= k)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; ++i)
    {
        for (int sum = 0; sum <= k; ++sum)
        {
            int notPick = dp[i - 1][sum];
            int pick = 0;
            if (arr[i] <= sum)
            {
                pick = dp[i - 1][sum - arr[i]];
            }
            dp[i][sum] = notPick + pick;
        }
    }
    return dp[n - 1][k];
}

int main()
{

    return 0;
}