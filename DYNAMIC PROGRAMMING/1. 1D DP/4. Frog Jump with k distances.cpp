// Minimal Cost
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
// TC O(N*k)
// SC O(N) + O(N)
int helper(int idx, vector<int> &arr, int k, vector<int> &dp)
{
    if (idx == 0)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int mini = INT_MAX;
    for (int i = 1; i <= k; ++i)
    {
        if (idx - i >= 0)
        {
            int jump = helper(idx - i, arr, k, dp) + abs(arr[idx] - arr[idx - i]);
            mini = min(mini, jump);
        }
    }
    return dp[idx] = mini;
}

int minimizeCost(int k, vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    return helper(n - 1, arr, k, dp);
}

// Tabulation
// TC O(N*k)
// SC O(N)
int solve(int k, vector<int> &arr, vector<int> &dp)
{
    dp[0] = 0;

    for (int i = 1; i < arr.size(); ++i)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; ++j)
        {
            if (i - j >= 0)
            {

                int jump = dp[i - j] + abs(arr[i] - arr[i - j]);
                minSteps = min(jump, minSteps);
            }
        }
        dp[i] = minSteps;
    }
    return dp[arr.size() - 1];
}
int _minimizeCost(int k, vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    return solve(k, arr, dp);
}

int main()
{
    int k = 3;
    vector<int> arr = {10, 30, 40, 50, 20};
    cout << minimizeCost(3, arr);
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << _minimizeCost(k, arr);
    return 0;
}