// Print Longest Common Subsequence
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(M*N) + O(M+N)
// SC O(M*N) + O(3)
string findLCS(int n, int m, string &s1, string &s2)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int j = 0; j <= m; ++j)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = 0;
    }

    for (int idx1 = 1; idx1 <= n; ++idx1)
    {
        for (int idx2 = 1; idx2 <= m; ++idx2)
        {
            if (s1[idx1 - 1] == s2[idx2 - 1])
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
    int len = dp[n][m];
    string ans = "";
    for (int i = 0; i < len; ++i)
    {
        ans += '$';
    }
    int index = len - 1;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans[index] = s1[i - 1];
            --index, --i, --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }
    return ans;
}

int main()
{
    string s1  = "abcab",s2 = "cbab";
    cout<<findLCS(5,4,s1,s2);
    return 0;
}