// 70. Climbing Stairs
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
int f(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return f(n, dp);
}

int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n);

    cout << endl;
    cout << "**********************************************************************" << endl;
    cout << "**********************************************************************" << endl;
    cout << "**********************************************************************" << endl;
    cout << "**********************************************************************" << endl;

    // Tabulation
    // TC O(n)
    // SC O(1)
    int help2 = 1; // (number of ways to reach the 0th step = 1 just stand there)
    int help1 = 1; // (number of ways to reach the 1st step = 1 just one jump)
    for (int i = 2; i <= n; ++i)
    {
        int curri = help1 + help2;
        help2 = help1;
        help1 = curri;
    }
    cout << help1;
    return 0;
}