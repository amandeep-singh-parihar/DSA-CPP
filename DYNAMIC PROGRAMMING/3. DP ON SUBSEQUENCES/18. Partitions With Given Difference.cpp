// Partitions With Given Difference
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Memoization
// TC O(N*K) + O(N)
// SC O(N*K) + O(N)
int f(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
{

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

    int notTake = f(i - 1, k, arr, dp);
    int take = 0;
    if (arr[i] <= k)
    {
        take = f(i - 1, k - arr[i], arr, dp);
    }

    return dp[i][k] = (notTake + take) % 1000000007;
}

int countPartitions(int n, int d, vector<int> &arr)
{

    int totSum = 0;
    for (int i = 0; i < n; ++i)
        totSum += arr[i];

    if (totSum - d < 0)
        return 0;
    if ((totSum - d) % 2)
        return 0;

    int s2 = (totSum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));

    return f(n - 1, s2, arr, dp);
}

// Tabulation
// TC O(N*K) + O(N)
// SC O(N*K)
int mod = (int)(1e9 + 7);
int findWays(vector<int> &num, int tar)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    if (num[0] == 0)
        dp[0][0] = 2; // 2 cases -pick and not pick
    else
        dp[0][0] = 1; // 1 case - not pick

    if (num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1; // 1 case -pick

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= tar; target++)
        {

            int notTaken = dp[ind - 1][target];

            int taken = 0;
            if (num[ind] <= target)
                taken = dp[ind - 1][target - num[ind]];

            dp[ind][target] = (notTaken + taken) % mod;
        }
    }
    return dp[n - 1][tar];
}

int _countPartitions(int n, int d, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - d < 0 || (totSum - d) % 2)
        return 0;

    return findWays(arr, (totSum - d) / 2);
}

int main()
{

    return 0;
}