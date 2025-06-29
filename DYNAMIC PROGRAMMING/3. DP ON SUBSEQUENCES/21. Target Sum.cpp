// 494. Target Sum
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Memoization
// TC O(N*target)
// SC O(N*target) + O(N)
int f(int i, int target, vector<int> &nums, map<pair<int, int>, int> &dp)
{
    if (i == nums.size())
    {
        return target == 0 ? 1 : 0;
    }

    if (dp.find({i, target}) != dp.end())
        return dp[{i, target}];

    int plus = f(i + 1, target - nums[i], nums, dp);
    int minus = f(i + 1, target + nums[i], nums, dp);

    return dp[{i, target}] = plus + minus;
}
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    map<pair<int, int>, int> dp;
    return f(0, target, nums, dp);
}

// Boils down the question into
// Count Partitions with given difference it means S1 - S2 = D
int f(int i, int k, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (k == 0 && nums[0] == 0)
            return 2;
        if (k == 0 || k == nums[0])
            return 1;
        return 0;
    }

    if (dp[i][k] != -1)
        return dp[i][k];

    int notTake = f(i - 1, k, nums, dp);
    int take = 0;
    if (nums[i] <= k)
    {
        take = f(i - 1, k - nums[i], nums, dp);
    }

    return dp[i][k] = (notTake + take);
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int totSum = 0;

    for (int i = 0; i < n; ++i)
        totSum += nums[i];

    if (totSum - target < 0)
        return 0;
    if ((totSum - target) % 2)
        return 0;

    int s2 = (totSum - target) / 2;
    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));

    return f(n - 1, s2, nums, dp);
}

// Tabulation for the above
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

            dp[ind][target] = notTaken + taken;
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
int findTargetSumWays(vector<int> &nums, int target)
{
    return _countPartitions(nums.size(), target, nums);
}

int main()
{
    vector<int>nums={1,1,1,1,1};
    int target = 3;
    cout<<findTargetSumWays(nums,target);
    return 0;
}