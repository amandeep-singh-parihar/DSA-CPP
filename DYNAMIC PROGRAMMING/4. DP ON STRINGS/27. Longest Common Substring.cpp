// Longest Common Substring
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(M*N)
// SC O(M*N)
int lcs(string &str1, string &str2)
{

    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; ++j)
        dp[0][j] = 0;
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;

    int ans = 0;
    for (int idx1 = 1; idx1 <= n; ++idx1)
    {
        for (int idx2 = 1; idx2 <= m; ++idx2)
        {
            if (str1[idx1 - 1] == str2[idx2 - 1])
            {
                dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                ans = max(ans, dp[idx1][idx2]);
            }
            else
            {
                dp[idx1][idx2] = 0;
            }
        }
    }
    return ans;
}

// TC O(M*N)
// SC O(M+M) = O(2M) = O(M)
int _lcs(string &str1, string &str2)
{

    int n = str1.size();
    int m = str2.size();

    vector<int>prev(m+1,0),curr(m+1,0);

    int ans = 0;
    for (int idx1 = 1; idx1 <= n; ++idx1)
    {
        for (int idx2 = 1; idx2 <= m; ++idx2)
        {
            if (str1[idx1 - 1] == str2[idx2 - 1])
            {
                curr[idx2] = 1 + prev[idx2 - 1];
                ans = max(ans, curr[idx2]);
            }
            else
            {
                curr[idx2] = 0;
            }
        }
        prev = curr;
    }
    return ans;
}

int main()
{
    string str1 = "abcjklp", str2 = "acjkp";
    cout << _lcs(str1, str2);
    return 0;
}