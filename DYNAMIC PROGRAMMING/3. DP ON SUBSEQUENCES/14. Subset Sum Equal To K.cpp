// Subset Sum Equal To K
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Memoization
// TC O(N*K)
// SC O(N*K) + O(N)
bool f(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;

    if (i == 0)
        return k == arr[i];
        
    if (dp[i][k] != -1)
        return dp[i][k];

    bool notTake = f(i - 1, k, arr, dp);
    bool take = false;
    if (arr[i] <= k)
    {
        take = f(i - 1, k - arr[i], arr, dp);
    }

    return dp[i][k] = notTake | take;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1)); // k+1 because the recursive solution
    // go from 0 to k which is k+1 columns
    // and for the n it is going from 0 to n-1 which is n rows
    return f(n - 1, k, arr, dp);
}

// Tabulation
// TC O(N*K)
// SC O(N*K)
bool _subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; ++i)
        dp[i][0] = true;

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
    return dp[n - 1][k];
}

int main()
{
    vector<int> arr = {4, 3, 2, 1};
    cout << subsetSumToK(4, 5, arr);
    return 0;
}