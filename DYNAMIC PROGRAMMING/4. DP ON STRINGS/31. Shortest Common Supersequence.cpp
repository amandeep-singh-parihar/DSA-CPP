// 1092. Shortest Common Supersequence
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(N*M)
// SC O(N*M)
string lcs(string &s, string &t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;
    for (int j = 0; j <= m; ++j)
        dp[0][j] = 0;

    for (int idx1 = 1; idx1 <= n; ++idx1)
    {
        for (int idx2 = 1; idx2 <= m; ++idx2)
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

    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans += s[i - 1];
            --i, --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += s[i - 1];
            --i;
        }
        else
        {
            ans += t[j - 1];
            --j;
        }
    }

    while (i > 0)
    {
        ans += s[i - 1];
        --i;
    }

    while (j > 0)
    {
        ans += t[j - 1];
        --j;
    }

    reverse(ans.begin(), ans.end());
}

string shortestCommonSupersequence(string str1, string str2)
{
    return lcs(str1, str2);
}

int main()
{

    return 0;
}