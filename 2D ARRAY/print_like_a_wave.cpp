#include <bits/stdc++.h>
using namespace std;

vector<int> wavePrint(const vector<vector<int>> &arr)
{
    int nRows = arr.size();
    int mCols = arr[0].size();
    vector<int> ans;

    for (int j = 0; j < mCols; j++)
    {
        if (j % 2 == 0)
        {
            // Top to bottom
            for (int i = 0; i < nRows; i++)
            {
                ans.push_back(arr[i][j]);
            }
        }
        else
        {
            // Bottom to top
            for (int i = nRows - 1; i >= 0; i--)
            {
                ans.push_back(arr[i][j]);
            }
        }
    }

    return ans;
}

int main()
{
    int nRows = 3, mCols = 3;
    vector<vector<int>> arr(nRows, vector<int>(mCols));

    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<int> result = wavePrint(arr);

    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
