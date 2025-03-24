// 1091. Shortest Path in Binary Matrix
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    if (grid[0][0] != 0)
        return -1;

    int n = grid.size();
    if (n == 1 && grid[0][0] == 0)
        return 1;

    vector<vector<int>> dist(n, vector<int>(n, 1e9));

    queue<pair<int, pair<int, int>>> q;
    q.push({1, {0, 0}});
    dist[0][0] = 1;
    int delRow[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int delCol[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    while (!q.empty())
    {
        auto it = q.front();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;
        q.pop();

        for (int i = 0; i < 8; ++i)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && 1 + dis < dist[nrow][ncol])
            {
                dist[nrow][ncol] = 1 + dis;
                if (nrow == n - 1 && ncol == n - 1)
                    return dist[n - 1][n - 1];
                q.push({dist[nrow][ncol], {nrow, ncol}});
            }
        }
    }
    return -1;
}

int main()
{
    return 0;
}