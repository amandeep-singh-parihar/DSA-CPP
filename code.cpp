#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int maxAcutance(vector<vector<int>> &image)
{
    int numRows = image.size();
    int numCols = image[0].size();
    vector<int> sumRow(numRows, 0);
    vector<int> sumCol(numCols, 0);

    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            if (image[i][j] == 1)
            {
                sumRow[i]++;
            }
        }
    }

    for (int j = 0; j < numCols; ++j)
    {
        for (int i = 0; i < numRows; ++i)
        {
            if (image[i][j] == 1)
            {
                sumCol[j]++;
            }
        }
    }

    int maxi = INT_MIN;
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            int count1_row_i = sumRow[i];
            int count1_col_j = sumCol[j];

            int count0_row_i = numCols - count1_row_i;
            int count0_col_j = numRows - count1_col_j;

            int current_acutance = (count1_row_i + count1_col_j) - (count0_row_i + count0_col_j);

            maxi = max(maxi, current_acutance);
        }
    }
    return maxi;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1, 1}, {1, 1, 1, 1}};
    cout << maxAcutance(image);
    return 0;
}