// 119. Pascals Triangle II
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int> getRow(int rowIndex)
{
    vector<vector<int>> ans(rowIndex + 1);
    for (int i = 0; i <= rowIndex; ++i)
    {
        ans[i].resize(i + 1);
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i)
            {
                ans[i][j] = 1;
            }
            else
            {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
    }
    vector<int> res;
    for (int i = 0; i <= rowIndex; ++i)
    {
        res.push_back(ans[rowIndex][i]);
    }
    return res;
}

int main()
{
    int rowIndex = 4;
    vector<int> ans = getRow(rowIndex);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}