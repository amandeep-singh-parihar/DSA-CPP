// Array partition with minimum difference
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision must needed and striver also said in the video that you can use map for storing dp;

// TC O()
// SC O()
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totSum = 0;
    for (int i = 0; i < n; ++i)
        totSum += arr[i];

    int k = totSum;

    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; ++i)
        dp[i][0] = true;

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int i = 1; i < n; ++i)
    {
        for (int target = 1; target <= k; ++target)
        {
            bool notTake = dp[i - 1][target];
            bool take = false;
            if (target >= arr[i])
            {
                take = dp[i - 1][target - arr[i]];
            }
            dp[i][target] = notTake | take;
        }
    }

    int mini = 1e9;
    for (int s1 = 0; s1 <= totSum / 2; ++s1)
    {
        if (dp[n - 1][s1] == true)
        {
            mini = min(mini, abs((totSum - s1) - s1));
        }
    }
    return mini;
}

int main()
{

    return 0;
}