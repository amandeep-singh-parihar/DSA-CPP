#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Memoization
// TC O(N*N)
// SC O(N*N) + O(N)
int n;
int f(int idx, int prev_idx, vector<int> &nums, vector<vector<int>> &dp)
{

    // base case -> out of nums
    if (idx == n)
        return 0;

    // dp check
    if (dp[idx][prev_idx + 1] != -1)
        return dp[idx][prev_idx + 1];

    // notTake
    int notTake = f(idx + 1, prev_idx, nums, dp);
    // take
    int take = -1e5;
    if (prev_idx == -1 || nums[idx] > nums[prev_idx])
    {
        take = 1 + f(idx + 1, idx, nums, dp);
    }

    return dp[idx][prev_idx + 1] = max(notTake, take);
}
int lengthOfLIS(vector<int> &nums)
{
    n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return f(0, -1, nums, dp);
}

// Tabulation
// TC O(N*N)
// SC O(N*N)
int _lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int idx = n - 1; idx >= 0; --idx)
    {
        for (int prev_idx = idx - 1; prev_idx >= -1; --prev_idx)
        {
            int notTake = dp[idx + 1][prev_idx + 1];
            int take = -1e9;
            if (prev_idx == -1 || nums[idx] > nums[prev_idx])
            {
                take = 1 + dp[idx + 1][idx + 1];
            }
            dp[idx][prev_idx + 1] = max(notTake, take);
        }
    }
    return dp[0][0];
}

// space optimization
// TC O(N*N)
// SC O(2N) -> O(N)
int __lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int idx = n - 1; idx >= 0; --idx)
    {
        for (int prev_idx = idx - 1; prev_idx >= -1; --prev_idx)
        {
            int notTake = prev[prev_idx + 1];
            int take = -1e9;
            if (prev_idx == -1 || nums[idx] > nums[prev_idx])
            {
                take = 1 + prev[idx + 1];
            }
            curr[prev_idx + 1] = max(notTake, take);
        }
        prev = curr;
    }
    return curr[0];
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << _lengthOfLIS(nums);
    return 0;
}