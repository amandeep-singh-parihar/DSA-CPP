// 1631. Path With Minimum Effort
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(n*m*4*log(n*m))
// SC O(n*m)
int minimumEffortPath(vector<vector<int>> &h)
{
    int n = h.size();
    int m = h[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;

    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if (row == n - 1 && col == m - 1)
            return diff;

        for (int i = 0; i < 4; ++i)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                int newEffort = max(diff, abs(h[row][col] - h[nrow][ncol]));
                // because You have to answer the max effort in the path
                // and then return minimum effort of all the paths
                if (newEffort < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = newEffort;
                    pq.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}};

    cout << "Minimum Effort: " << minimumEffortPath(heights) << endl;
    return 0;
}