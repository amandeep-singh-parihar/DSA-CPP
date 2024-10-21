// 118. Pascals Triangle
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans(numRows);
    for (int i = 0; i < numRows; ++i)
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
    return ans;
}

int main()
{
    int numRows = 5;
    vector<vector<int>> ans = generate(numRows);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}