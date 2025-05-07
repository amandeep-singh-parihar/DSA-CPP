// 120. Triangle
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Revision 1

// Memoization
// TC O(N^2)
// SC O(N^2)
int f(int i, int j, int n, vector<vector<int>> &dp, vector<vector<int>> &triangle)
{
    if (i == n - 1)
        return triangle[n - 1][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int down = f(i + 1, j, n, dp, triangle);
    int diagonal = f(i + 1, j + 1, n, dp, triangle);

    return dp[i][j] = triangle[i][j] + min(down, diagonal);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(0, 0, n, dp, triangle);
    // in this memoization we go from 0 to n-1 because the starting is fixed but the ending is variable
}

// Tabulation
// TC O(N^2)
// SC O(N)
int _minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int j = 0; j < n; ++j)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = i; j >= 0; --j)
        {
            int down = dp[i + 1][j];
            int diagonal = dp[i + 1][j + 1];
            dp[i][j] = triangle[i][j] + min(down, diagonal);
        }
    }
    return dp[0][0];
    // so if the memoization is from bottom to up then the tabulation must be from top to bottom
    // inverse of memoization here we go from n-2 to 0 , n-2 because if run a loop reverse start from n-1,
    // here i+1 is the term if i go from n-1 then at a condition n-1+1 = n out of bound so go from n-2.
}

// Space optimization
// TC O(M*N)
// SC O(N)
int __minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> front(n, 1e9), curr(n, 1e9);

    for (int col = 0; col < n; ++col)
    {
        front[col] = triangle[n - 1][col];
    }

    for (int row = n - 2; row >= 0; --row)
    {
        for (int col = row; col >= 0; --col)
        {
            int down = front[col];
            int diagonal = front[col + 1];
            curr[col] = triangle[row][col] + min(down, diagonal);
        }
        front = curr;
    }
    return front[0];
}

int main()
{
    vector<vector<int>> triangle = {{2},
                                    {3, 4},
                                    {6, 5, 7},
                                    {4, 1, 8, 3}};
    cout << __minimumTotal(triangle);
    return 0;
}