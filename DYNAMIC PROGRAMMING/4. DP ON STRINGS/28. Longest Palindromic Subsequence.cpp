// 516. Longest Palindromic Subsequence
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// MLE
// BRUTE
bool isPalindrome(string &ans)
{
    int i = 0, j = ans.size() - 1;
    while (i < j)
    {
        if (ans[i] != ans[j])
            return false;
        ++i, --j;
    }
    return true;
}
int cnt(vector<string> &ans)
{
    int maxi = INT_MIN;
    for (auto it : ans)
    {
        if (isPalindrome(it))
        {
            maxi = max(maxi, static_cast<int>(it.size()));
        }
    }
    return maxi;
}
void helper(int i, string &s, vector<string> &ans, string &temp)
{
    if (i >= s.size())
    {
        ans.push_back(temp);
        return;
    }

    // incluce
    temp.push_back(s[i]);
    helper(i + 1, s, ans, temp);
    temp.pop_back();

    // exclude
    helper(i + 1, s, ans, temp);
}
int longestPalindromeSubseq(string s)
{
    vector<string> ans;
    string temp;
    helper(0, s, ans, temp);
    return cnt(ans);
}

// MEMOIZATION
// TC O(N*N)
// SC O(N*N) + O(N*N)
int f(int idx1, int idx2, string &s, string &t, vector<vector<int>> &dp)
{
    if (idx1 == 0 || idx2 == 0)
        return 0;

    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    if (s[idx1 - 1] == t[idx2 - 1])
    {
        return dp[idx1][idx2] = 1 + f(idx1 - 1, idx2 - 1, s, t, dp);
    }
    else
    {
        return dp[idx1][idx2] = max(f(idx1 - 1, idx2, s, t, dp),
                                    f(idx1, idx2 - 1, s, t, dp));
    }
}
int _longestPalindromeSubseq(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return f(n, n, s, t, dp);
}

// Tabulation
// TC O(N*N)
// SC O(N*N)
int lcs(string &s, string &t)
{
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // base case
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
                dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
            }
        }
    }
    return dp[n][n];
}
int __longestPalindromeSubseq(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.size();
    return lcs(s, t);
}

// Space optimized
// TC O(N*N)
// SC O(2N) = O(N)
int lcs(string &s, string &t)
{
    int n = s.size();
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    // base case
    // for(int j = 0;j<=n;++j) dp[0][j] = 0;
    // for(int i = 0;i<=n;++i) dp[i][0] = 0;

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
                curr[idx2] = max(prev[idx2], curr[idx2 - 1]);
            }
        }
        prev = curr;
    }
    return curr[n];
}
int ___longestPalindromeSubseq(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.size();
    return lcs(s, t);
}

int main()
{

    return 0;
}