// DP 42. Printing Longest Increasing Subsequence | Tabulation | Algorithm
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int idx = 0; idx < n; ++idx)
    {
        for (int prev_idx = 0; prev_idx <= idx - 1; ++prev_idx)
        {
            if (nums[prev_idx] < nums[idx])
            {
                dp[idx] = max(1 + dp[prev_idx], dp[idx]);
            }
        }
        maxi = max(maxi, dp[idx]);
    }
    int finalMaxi = maxi;
    // cout << maxi;
    cout << endl
         << "*************" << endl;
    int index = -1; 
    for (int i = 0; i < n; ++i)
    {
        if (dp[i] == maxi)
        {
            index = i;
        }
    }
    vector<int> ans = {nums[index]};
    for (int i = index; i >= 0; --i)
    {
        if (maxi - 1 == dp[i])
        {
            maxi--;
            ans.push_back(nums[i]);
        }
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return finalMaxi;
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums);
    return 0;
}