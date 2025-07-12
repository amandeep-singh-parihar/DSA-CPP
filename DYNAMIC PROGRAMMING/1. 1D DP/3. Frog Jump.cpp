// Frog Jump
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Revision 2

// Memoization
// TC O(N)
// SC O(N) + O(N)
int helper(int i, vector<int> &height, vector<int> &dp)
{
    // as this is memoization solution so You are going from n-1 to 0
    if (i == 0) // cost required to reach from 0 to 0 is 0 itself
    {
        return 0;
    }

    if (dp[i] != -1) // dp check
        return dp[i];

    // left means jump1
    // right means jump2
    int left = helper(i - 1, height, dp) + abs(height[i] - height[i - 1]);
    int right = INT_MAX;
    if (i > 1)
    {
        right = helper(i - 2, height, dp) + abs(height[i] - height[i - 2]);
    }

    // at the end you only have to take the min of all the jumps
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

    int prev2 = 0; // this is 2 previous then the current
    int prev1 = 0; // prev2 is also 0 because we don’t need it in the first iteration (i = 1), and we’ll compute it as we go, fro initilization it will be anything even -1132132, or 10, 99 afther the first iteration it got its right value
    //    0      1        2       3       4 ....... n-1
    //  prev2  prev1    curr

    // now prev1 is 0 ok because from 0 to 0 is 0 but why prev2 is zero because as the iterations move forward it will calculate in the future for, for the first iteration where the jump from 0 to 1 only need prev1
    // after the first iteration complete the prev2 got his value there
    for (int i = 1; i < n; ++i)
    {
        int left = prev1 + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = prev2 + abs(height[i] - height[i - 2]);

        int curri = min(left, right);
        prev2 = prev1;
        prev1 = curri;
    }

    return prev1;
}

int main()
{
    vector<int> height = {30, 20, 50, 10, 40};
    cout << minCost(height) << endl;
    cout << "***************************************************************************" << endl;
    cout << _minCost(height);
    return 0;
}