// 583. Delete Operation for Two Strings
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// space optimization pending when you revise do that

// Tabulation
// TC O(N*M)
// SC O(N*M)
int lcs(string &s, string &t)
{

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base case
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

    return dp[n][m];
}
int minDistance(string word1, string word2)
{
    return (word1.size() + word2.size()) - 2 * lcs(word1, word2);
}

int main()
{
    string word1 = "sea", word2 = "eat";
    cout<<minDistance(word1,word2);
    return 0;
}