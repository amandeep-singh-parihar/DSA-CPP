#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void setZeroes(vector<vector<int>> &matrix)
{
    int col0 = 1;
#pragma unroll
    for (int i = 0; i < matrix.size(); ++i)
    {
#pragma unroll
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == 0)
            {
                // mark the ith row
                matrix[i][0] = 0;
                // mark the jth col
                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }
#pragma unroll

    for (int i = 1; i < matrix.size(); ++i)
    {
#pragma unroll
        for (int j = 1; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] != 0)
            {
                // check for col & row
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if (matrix[0][0] == 0)
    {
#pragma unroll

        for (int j = 0; j < matrix[0].size(); ++j)
            matrix[0][j] = 0;
    }

    if (col0 == 0)
    {
#pragma unroll

        for (int i = 0; i < matrix.size(); ++i)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    // vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> matrix = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}};
    cout << "_________________ORIGINAL MATRIX___________________" << endl;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "_________________RESULT MATRIX___________________" << endl;

    setZeroes(matrix);
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}