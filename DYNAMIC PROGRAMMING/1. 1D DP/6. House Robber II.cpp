// 213. House Robber II
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Revision 3

int robHelper(vector<int> &nums)
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
int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    vector<int> temp1, temp2;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != nums.size() - 1)
            temp2.push_back(nums[i]);
    }
    return max(robHelper(temp1), robHelper(temp2));
}

int main()
{

    return 0;
}