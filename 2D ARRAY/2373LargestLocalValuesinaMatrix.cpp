#include <bits/stdc++.h>
using namespace std;

int findMax(vector<vector<int>> &grid, int x, int y)
{
    int maxi = INT_MIN;
#pragma unroll
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            maxi = max(maxi, grid[i][j]);
        }
    }
    return maxi;
}

vector<vector<int>> largestLocal(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, 0));
#pragma unroll
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < n - 2; ++j)
        {
            maxLocal[i][j] = findMax(grid, i, j);
        }
    }
    return maxLocal;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> grid = {{9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2}};
    vector<vector<int>> result = largestLocal(grid);

    cout << "Result:" << endl;
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}