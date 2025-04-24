//  Rod cutting problem
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Memoization
// TC O(M*N)
// SC O(M*N) + O(target)
int f(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return N * price[0];
    }

    if (dp[ind][N] != -1)
        return dp[ind][N];

    int notTake = f(ind - 1, N, price, dp);
    int take = -1e9;
    int rodLength = ind + 1;
    if (rodLength <= N)
    {
        take = price[ind] + f(ind, N - rodLength, price, dp);
    }

    return dp[ind][N] = max(notTake, take);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n - 1, n, price, dp);
}

// Tabulation
// TC O(M*N)
// SC O(M*N)
int _cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int N = 0; N <= n; ++N)
        dp[0][N] = N * price[0];

    for (int ind = 1; ind < n; ++ind)
    {
        for (int N = 0; N <= n; ++N)
        {

            int notTake = dp[ind - 1][N];
            int take = -1e9;
            int rodLength = ind + 1;
            if (rodLength <= N)
            {
                take = price[ind] + dp[ind][N - rodLength];
            }
            dp[ind][N] = max(notTake, take);
        }
    }

    return dp[n - 1][n];
}

// Space optimization
// TC O(M*N)
// SC O(N+1)
int __cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int N = 0; N <= n; ++N)
        prev[N] = N * price[0];

    for (int ind = 1; ind < n; ++ind)
    {
        for (int N = 0; N <= n; ++N)
        {

            int notTake = prev[N];
            int take = -1e9;
            int rodLength = ind + 1;
            if (rodLength <= N)
            {
                take = price[ind] + curr[N - rodLength];
            }
            curr[N] = max(notTake, take);
        }
        prev = curr;
    }
    return prev[n];
}

int main()
{
    vector<int> price = {2, 5, 7, 8, 10};
    int n = 5;
    cout << __cutRod(price, n);
    return 0;
}