// 115. Distinct Subsequences
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
// SC O(M*N) + (M+N)
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{

    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
    {
        return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
    }
    else
    {
        return dp[i][j] = f(i - 1, j, s, t, dp);
    }
}
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(n - 1, m - 1, s, t, dp);
}

// Tabulation
// TC O(M*N)
// SC O(M*N)
int _numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

    // below here if you run the loop II first then the value of dp[0][0] = 1
    // and when after the i loop if you run the j loop the value of dp[0][0] = 0;
    // which is confilicting so run in this order or either run the j loop from 1;
    // or don't run the j loop as the vector is initilly zero

    for (int j = 0; j <= m; ++j)
        dp[0][j] = 0;

    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return (int)dp[n][m];
}

// Space optimization code
// SC O(M+M) = O(2M) = O(M)
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<double> prev(m + 1, 0), curr(m + 1, 0);

    prev[0] = curr[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = prev[j - 1] + prev[j];
            }
            else
            {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }

    return (int)prev[m];
}

int main()
{
    string s = "rabbbit", t = "rabbit";
    cout << _numDistinct(s, t);
    return 0;
}