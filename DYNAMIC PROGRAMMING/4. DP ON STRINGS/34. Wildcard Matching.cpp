// 44. Wildcard Matching
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
// s contains only lowercase alpha
// p contains lowercase + ? + *
bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{

    // if the s and p both exhausted
    if (i < 0 && j < 0)
        return true;

    // if the p exhausted but the s is still out there it means they don't match
    if (j < 0 && i >= 0)
        return false;

    // if the s exhausted but the p not, now the p must contain "*" as it can be of 0 length
    if (i < 0 && j >= 0)
    {
        for (int ii = 0; ii <= j; ++ii)
        {
            if (p[ii] != '*')
                return false;
        }
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == p[j] || p[j] == '?')
    {
        return dp[i][j] = f(i - 1, j - 1, s, p, dp);
    }
    else if (p[j] == '*')
    {
        return dp[i][j] = f(i - 1, j, s, p, dp) | f(i, j - 1, s, p, dp);
    }
    else
    {
        return dp[i][j] = false;
    }
}


// Tabulation
// TC O(M*N)
// SC O(M*N)
bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(n - 1, m - 1, s, p, dp);
}

bool _isMatch(string s, string p) {
    
    int n = s.size();
    int m = p.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // base case
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i)
        dp[i][0] = false;
    for (int j = 1; j <= m; ++j) {
        bool flag = true;
        for (int ii = 1; ii <= j; ++ii) {
            if (p[ii - 1] != '*') {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j-1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            } else {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}

// space optimization pending

int main()
{
    string s = "aa", p = "*";
    cout << isMatch(s, p);
    return 0;
}