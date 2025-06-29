#include <bits/stdc++.h>
using namespace std;

int matrixScore(vector<vector<int>> &arr)
{
    int row = arr.size();
    int col = arr[0].size();

    // flip the row which start with 0
    for (int i = 0; i < row; i++)
    {
        if (arr[i][0] == 0)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = 1 - arr[i][j];
            }
        }
    }

    // set the cols by counting the zeros
    for (int j = 1; j < col; j++)
    {
        int countZeros = 0;
        for (int i = 0; i < row; i++)
        {
            if (arr[i][j] == 0)
            {
                countZeros++;
            }
        }

        if (countZeros > row - countZeros)
        {
            for (int i = 0; i < row; i++)
            {
                arr[i][j] = 1 - arr[i][j];
            }
        }
    }

    int score=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int colScore=arr[i][j]<<(col-j-1);
            score+=colScore;
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
    cout<<matrixScore(grid);

    return 0;
}