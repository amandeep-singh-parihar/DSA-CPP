// 198. House Robber
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Revision 3

// Memoization
// TC O(N)
// SC O(N) + O(N)
int robHelper(int idx, vector<int> &nums, vector<int> &dp)
{
    if (idx == 0) // if the idx reach 0 it means You haven't pick the idx=1 so just pick this for the max
        return nums[idx];
    if (idx < 0)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int maxi = INT_MIN;
    int rob1 = nums[idx] + robHelper(idx - 2, nums, dp); // pick this index and not the adjacent element
    int rob2 = robHelper(idx - 1, nums, dp);             // not pick the element so pick the adjacent

    maxi = max(rob1, rob2);
    return dp[idx] = maxi;
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return robHelper(n - 1, nums, dp);
}

// Tabulation
// TC O(N)
// SC O(N)
int _rob(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
        return nums[0];

    vector<int> dp(n + 1, 0);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i)
    {
        int take = nums[i] + dp[i - 2];
        int notTake = dp[i - 1];
        dp[i] = max(take, notTake);
    }

    return dp[n - 1];
}

// Space Optimization
// TC O(N)
// SC O(1)
int __rob(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
        return nums[0];

    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i)
    {
        int take = nums[i] + prev2;
        int notTake = 0 + prev1;
        int curr = max(take, notTake);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << rob(nums) << endl;
    cout << _rob(nums) << endl;
    cout << __rob(nums) << endl;

    return 0;
}