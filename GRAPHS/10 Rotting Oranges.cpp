// 994. Rotting Oranges
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
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    int fresh_oranges = 0;   // take the fresh oranges count
    queue<pair<int, int>> q; // create a queue {row,col}
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 2) // if that element is rotton orange push it in the queue
            {
                q.push({i, j});
            }
            if (grid[i][j] == 1) // if that element is a fresh orange count it
            {
                ++fresh_oranges;
            }
        }
    }
    while (!q.empty()) // while the q is not empty
    {
        int s = q.size();       // take the currect size of the q
        if (fresh_oranges == 0) // if the fresh oranges count is 0
            return ans;         // return the ans

        while (s--) // till the q not empty
        {
            auto it = q.front(); // take the front
            q.pop();             // pop it

            int i = it.first;  // take the row
            int j = it.second; // take the col

            if (i > 0) // check if someone is exits on the left
            {
                if (grid[i - 1][j] == 1)
                {
                    --fresh_oranges;    // dec the fresh oranges count
                    grid[i - 1][j] = 2; // mark the orange as rotton
                    q.push({i - 1, j}); // push it in the q
                }
            }
            if (j > 0) // check if someone is exits on the upper
            {
                if (grid[i][j - 1] == 1)
                {
                    --fresh_oranges;
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1});
                }
            }
            if (i < n - 1) // check if someone is exits on the right
            {
                if (grid[i + 1][j] == 1)
                {
                    --fresh_oranges;
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j});
                }
            }
            if (j < m - 1) // check if someone is exits on the down
            {
                if (grid[i][j + 1] == 1)
                {
                    --fresh_oranges;
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1});
                }
            }
        }
        ++ans; // count everytime we mark one level
    }
    return fresh_oranges == 0 ? ans : -1; // if the fresh oranges is not 0 then return -1
}

// We can also short the code by taking care of repetative if statement
int _orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    int fresh_oranges = 0;   // take the fresh oranges count
    queue<pair<int, int>> q; // create a queue {row,col}
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 2) // if that element is rotton orange push it in the queue
            {
                q.push({i, j});
            }
            if (grid[i][j] == 1) // if that element is a fresh orange count it
            {
                ++fresh_oranges;
            }
        }
    }
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};
    while (!q.empty() && fresh_oranges)
    {
        int size = q.size();
        while (size--)
        {
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            for (int i = 0; i < 4; ++i)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1)
                {
                    --fresh_oranges;
                    grid[nrow][ncol] = 2;
                    q.push({nrow, ncol});
                }
            }
        }
        ++ans;
    }
    return fresh_oranges == 0 ? ans : -1;
}

int main()
{
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};

    int result = orangesRotting(grid);
    cout << "Minimum time to rot all oranges: " << result << endl;

    return 0;
}