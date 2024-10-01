#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void helper(vector<int> &candidates, vector<vector<int>> &res, vector<int> &temp, int target, int index)
{
    // base case
    if (target == 0)
    {
        res.push_back(temp);
        return;
    }

    if (target < 0)
    {
        return;
    }

    for (int i = index; i < candidates.size(); ++i)
    {
        temp.push_back(candidates[i]);
        helper(candidates, res, temp, target - candidates[i], i);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> temp;
    helper(candidates, res, temp, target, 0);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> candidates(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> candidates[i];
    }
    int target;
    cin >> target;
    vector<vector<int>> ans = combinationSum(candidates, target);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}