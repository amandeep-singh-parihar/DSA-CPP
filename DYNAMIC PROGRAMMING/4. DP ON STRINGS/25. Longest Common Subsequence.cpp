// 1143. Longest Common Subsequence
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
// SC O(M*N) + O(M+N) here M+N bcz if no string matched alternative deletion of strings takes place which results
// in M + N. eg "AB" and "CD"
int f(int idx1, int idx2, string &text1, string &text2, vector<vector<int>> &dp)
{
    if (idx1 < 0 || idx2 < 0)
        return 0;

    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    if (text1[idx1] == text2[idx2])
    {
        return dp[idx1][idx2] = 1 + f(idx1 - 1, idx2 - 1, text1, text2, dp);
    }
    else
    {
        return dp[idx1][idx2] = max(f(idx1 - 1, idx2, text1, text2, dp),
                                    f(idx1, idx2 - 1, text1, text2, dp));
    }
}
int longestCommonSubsequence(string text1, string text2)
{
    int n1 = text1.size();
    int n2 = text2.size();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return f(n1 - 1, n2 - 1, text1, text2, dp);
}

// Tabulation
// TC O(M*N)
// SC O(M*N)
int _longestCommonSubsequence(string text1, string text2)
{
    int n1 = text1.size();
    int n2 = text2.size();
    // index shifting
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    // the loops below go till the last bcz now the indeces are shited by 1
    for (int j = 0; j <= n2; ++j)
        dp[0][j] = 0;
    for (int i = 0; i <= n1; ++i)
        dp[i][0] = 0;

    for (int idx1 = 1; idx1 <= n1; ++idx1)
    {
        for (int idx2 = 1; idx2 <= n2; ++idx2)
        {
            if (text1[idx1 - 1] == text2[idx2 - 1])
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
    return dp[n1][n2];
}

// Space optimization
// TC O(M*N)
// SC O(M)
int __longestCommonSubsequence(string text1, string text2)
{
    int n1 = text1.size();
    int n2 = text2.size();
    vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);
    for (int j = 0; j <= n2; ++j)
        prev[j] = 0;

    for (int idx1 = 1; idx1 <= n1; ++idx1)
    {
        for (int idx2 = 1; idx2 <= n2; ++idx2)
        {
            if (text1[idx1 - 1] == text2[idx2 - 1])
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
    return prev[n2];
}

int main()
{
    string text1 = "abcde", text2 = "ace";
    cout << longestCommonSubsequence(text1, text2);
    return 0;
}