#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int fib(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    // dp check
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int _fib(int n)
{
    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; ++i)
    {
        int curri = prev2 + prev1;
        prev2 = prev1;
        prev1 = curri;
    }
    cout << prev1;
}

int main()
{

    return 0;
}