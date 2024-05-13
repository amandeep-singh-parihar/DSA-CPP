#include <bits/stdc++.h>
using namespace std;

int matrixScore(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    // check all rows with this
    for (int i = 0; i < row; i++)
    {
        if (grid[i][0] == 0)
        {
            for (int j = 0; j < col; j++)
            {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }

    // go for col but not for the first col;
    for (int j = 1; j < col; j++)
    {
        int cZ = 0;
        for (int i = 0; i < row; i++)
        {
            if (grid[i][j] == 0)
            {
                cZ++;
            }
        }

        if (cZ > row - cZ)
        {
            for (int i = 0; i < row; i++)
            {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }

    int score = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int colScore = grid[i][j] << (col - j - 1);
            score += colScore;
        }
    }

    return score;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> grid = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};

    cout << matrixScore(grid);

    return 0;
}