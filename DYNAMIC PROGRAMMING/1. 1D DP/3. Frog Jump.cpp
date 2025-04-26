// Frog Jump
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Revision 1

// Memoization
// TC O(N)
// SC O(N) + O(N)
int helper(int i, vector<int> &height, vector<int> &dp)
{
    if (i == 0)
    {
        return 0;
    }

    if (dp[i] != -1)
        return dp[i];

    int left = helper(i - 1, height, dp) + abs(height[i] - height[i - 1]);
    int right = INT_MAX;
    if (i > 1)
    {
        right = helper(i - 2, height, dp) + abs(height[i] - height[i - 2]);
    }

    return dp[i] = min(left, right);
}

int minCost(vector<int> &height)
{
    int n = height.size();
    vector<int> dp(n + 1, -1);
    return helper(n - 1, height, dp);
}

// Tabulation
// TC O(N)
// SC O(N)
int __minCost(vector<int> &height)
{
    int n = height.size();
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);

    for (int i = 2; i < n; ++i)
    {
        int left = dp[i - 1] + abs(height[i] - height[i - 1]);
        int right = dp[i - 2] + abs(height[i] - height[i - 2]);
        dp[i] = min(left, right);
    }

    return dp[n - 1];
}
// Tabulation (space optimization)
// TC O(N)
// SC O(1)
int _minCost(vector<int> &height)
{
    int n = height.size();
    if (n == 0)
        return 0;

    int prev2 = 0;
    int prev = 0;
    for (int i = 1; i < n; ++i)
    {
        int left = prev + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = prev2 + abs(height[i] - height[i - 2]);

        int curri = min(left, right);
        prev2 = prev;
        prev = curri;
    }

    return prev;
}

int main()
{
    vector<int> height = {30, 20, 50, 10, 40};
    cout << minCost(height) << endl;
    cout << "***************************************************************************" << endl;
    cout << _minCost(height);
    return 0;
}