// 1312. Minimum Insertion Steps to Make a String Palindrome
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Tabulation
// TC O(N*N)
// SC O(N*N)
int lcs(string &s, string &t)
{
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int j = 0; j <= n; ++j)
        dp[0][j] = 0;
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;

    for (int idx1 = 1; idx1 <= n; ++idx1)
    {
        for (int idx2 = 1; idx2 <= n; ++idx2)
        {
            if (s[idx1 - 1] == t[idx2 - 1])
            {
                dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
            }
            else
            {
                dp[idx1][idx2] =
                    max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
            }
        }
    }
    return dp[n][n];
}
int minInsertions(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    int ans = lcs(s, t);
    int n = s.size();
    return n - ans;
}

// Space optimization
// TC O(N*N)
// SC O(N)
int _lcs(string &s, string &t)
{
    int n = s.size();
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    // for (int j = 0; j <= n; ++j)
    //     dp[0][j] = 0;
    // for (int i = 0; i <= n; ++i)
    //     dp[i][0] = 0;

    for (int idx1 = 1; idx1 <= n; ++idx1)
    {
        for (int idx2 = 1; idx2 <= n; ++idx2)
        {
            if (s[idx1 - 1] == t[idx2 - 1])
            {
                curr[idx2] = 1 + prev[idx2 - 1];
            }
            else
            {
                curr[idx2] =
                    max(prev[idx2], curr[idx2 - 1]);
            }
        }
        prev = curr;
    }
    return curr[n];
}
int _minInsertions(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    int ans = _lcs(s, t);
    int n = s.size();
    return n - ans;
}

int main()
{

    return 0;
}