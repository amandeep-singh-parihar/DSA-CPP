// 416. Partition Equal Subset Sum
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
bool f(int i, int k, vector<int> &nums, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;

    if (i == 0)
        return (nums[0] == k);

    if (dp[i][k] != -1)
        return dp[i][k];

    int notTake = f(i - 1, k, nums, dp);
    int take = false;
    if (k >= nums[i])
    {
        take = f(i - 1, k - nums[i], nums, dp);
    }
    return dp[i][k] = take | notTake;
}
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += nums[i];
    }
    if (sum % 2 != 0)
        return false;
    int k = sum / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, nums, dp);
}

// Tabulation
// TC O(N*K) + O(N)
// SC O(N*K)
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += nums[i];
    }
    if (sum % 2 != 0)
        return false;
    int k = sum / 2;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = true;
    }
    if (nums[0] <= k)
        dp[0][nums[0]] = true;

    for (int i = 1; i < n; ++i)
    {
        for (int target = 1; target <= k; ++target)
        {
            bool notTake = dp[i - 1][target];
            int take = false;
            if (target >= nums[i])
            {
                take = dp[i - 1][target - nums[i]];
            }
            dp[i][target] = notTake | take;
        }
    }
    return dp[n - 1][k];
}

int main()
{

    return 0;
}