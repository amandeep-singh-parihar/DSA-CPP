//  Chocolate Pickup
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
// TC O(N*M*M)*O(9)
// SC O(N*M*M)+O(N)
int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
        return -1e8;

    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    // explore all path
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; ++dj1)
    {
        for (int dj2 = -1; dj2 <= 1; ++dj2)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            value += f(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return f(0, 0, c - 1, r, c, grid, dp);
}

// Tabulation
// TC O(N*M*M)*O(9)
// SC O(N*M*M)
int _maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
    for (int j1 = 0; j1 < c; ++j1)
    {
        for (int j2 = 0; j2 < c; ++j2)
        {
            if (j1 == j2)
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            else
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    for (int i = r - 2; i >= 0; --i)
    {
        for (int j1 = 0; j1 < c; ++j1)
        {
            for (int j2 = 0; j2 < c; ++j2)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; ++dj1)
                {
                    for (int dj2 = -1; dj2 <= 1; ++dj2)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 >= 0 && j2 + dj2 < c)
                            value += dp[i + 1][j1 + dj1][j2 + dj2];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][c - 1];
}

// Space optimization
// TC O(M*N*N*9)
// SC O(N*N)
int __maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
    vector<vector<int>> front(c, vector<int>(c, 0));
    vector<vector<int>> curr(c, vector<int>(c, 0));

    for (int j1 = 0; j1 < c; ++j1)
    {
        for (int j2 = 0; j2 < c; ++j2)
        {
            if (j1 == j2)
                front[j1][j2] = grid[r - 1][j1];
            else
                front[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    for (int i = r - 2; i >= 0; --i)
    {
        for (int j1 = 0; j1 < c; ++j1)
        {
            for (int j2 = 0; j2 < c; ++j2)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; ++dj1)
                {
                    for (int dj2 = -1; dj2 <= 1; ++dj2)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 >= 0 && j2 + dj2 < c)
                            value += front[j1 + dj1][j2 + dj2];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }
    return front[0][c - 1];
}

int main()
{
    vector<vector<int>> grid = {{2, 3, 1, 2},
                                {3, 4, 2, 2},
                                {5, 6, 3, 5}};
    cout << _maximumChocolates(3, 4, grid);
    return 0;
}