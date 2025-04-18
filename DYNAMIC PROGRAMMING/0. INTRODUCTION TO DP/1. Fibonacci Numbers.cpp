// Introduction to DP
// 509. Fibonacci Number
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
// TC O(n)
// SC O(n) + O(n)
int fib(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1) // step 3 : check if for this n it is computed or not
        return dp[n];

    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp); // step 2 : store the result in the dp[n]
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1); // step 1 : Declare a dp
    cout << fib(n, dp) << endl;

    cout << "****************************************************************************" << endl;
    cout << "****************************************************************************" << endl;
    cout << "****************************************************************************" << endl;
    cout << "****************************************************************************" << endl;

    // Tabulation
    // TC O(n)
    // SC O(1)
    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; ++i)
    {
        int curri = prev2 + prev1;
        prev2 = prev1;
        prev1 = curri;
    }
    cout << prev1;
    return 0;
}