// 72. Edit Distance
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
// SC O(M*N) + O(M+N)
int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
{

    if (i == 0)
        return j;

    if (j == 0)
        return i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (word1[i - 1] == word2[j - 1])
    {
        return dp[i][j] = f(i - 1, j - 1, word1, word2, dp);
    }
    else
    {
        return dp[i][j] = min(1 + f(i, j - 1, word1, word2, dp),
                              min(1 + f(i - 1, j, word1, word2, dp),
                                  1 + f(i - 1, j - 1, word1, word2, dp)));
    }
}
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    // one base indexing
    // -1 -> 0
    //  0 -> 1
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return f(n, m, word1, word2, dp);
}

// Tabulation
// TC O(M*N)
// SC O(M*N)
int _minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    // one base indexing
    // -1 -> 0
    //  0 -> 1
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; ++j)
        dp[0][j] = j;
    for (int i = 1; i <= n; ++i)
        dp[i][0] = i;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] =
                    min(1 + dp[i][j - 1], min(1 + dp[i - 1][j], 1 + dp[i - 1][j - 1]));
            }
        }
    }

    return dp[n][m];
}


// space optimization
int __minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    // one base indexing
    // -1 -> 0
    //  0 -> 1
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int j = 0; j <= m; ++j)
        prev[j] = j;

    for (int i = 1; i <= n; ++i) {
        curr[0] = i;
        for (int j = 1; j <= m; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                curr[j] = prev[j - 1];
            } else {
                curr[j] =
                    min(1 + curr[j - 1], min(1 + prev[j], 1 + prev[j - 1]));
            }
        }
        prev = curr;
    }

    return prev[m];
}

int main()
{

    return 0;
}