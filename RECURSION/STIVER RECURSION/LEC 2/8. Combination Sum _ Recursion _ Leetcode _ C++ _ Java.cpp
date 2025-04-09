// L8. Combination Sum | Recursion | Leetcode | C++ | Java
// 39. Combination Sum
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O((2^T) * K)  T->target sum K->number of combination generated
// SC O(K * T)
void helper(int i, vector<int> &candidates, int target,
            vector<vector<int>> &ans, vector<int> &output)
{
    if (i == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(output);
        }
        return;
    }

    // include
    if (candidates[i] <= target)
    {
        output.push_back(candidates[i]);
        helper(i, candidates, target - candidates[i], ans, output);
        output.pop_back();
    }

    // exclude
    helper(i + 1, candidates, target, ans, output);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> output;
    helper(0, candidates, target, ans, output);
    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve(vector<int> &candidates, int target, vector<vector<int>> &res,
           vector<int> &temp, int index)
{
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
        solve(candidates, target - candidates[i], res, temp, i);
        temp.pop_back();
    }
}
vector<vector<int>> _combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> temp;
    int index = 0;
    solve(candidates, target, res, temp, index);
    return res;
}

int main()
{
    vector<int> candidates = {2, 3, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum(candidates, target);
    for (auto it : ans)
    {
        for (auto _it : it)
        {
            cout << _it << " ";
        }
        cout << endl;
    }
    return 0;
}