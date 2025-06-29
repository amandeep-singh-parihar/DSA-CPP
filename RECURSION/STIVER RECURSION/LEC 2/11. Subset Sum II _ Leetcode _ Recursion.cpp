// L11. Subset Sum II | Leetcode | Recursion
// 90. Subsets II
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute Force
// TC: O(2ⁿ × k × log(2ⁿ)) k = average length of each subset
// SC: O(2ⁿ × k) n = size of nums
void solve(int i, vector<vector<int>> &ans, vector<int> &ds,
           vector<int> &nums)
{
    if (i == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    ds.push_back(nums[i]);
    solve(i + 1, ans, ds, nums);
    ds.pop_back();

    solve(i + 1, ans, ds, nums);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0, ans, ds, nums);
    set<vector<int>> mySet(ans.begin(), ans.end());
    return vector<vector<int>>(mySet.begin(), mySet.end());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// TC: O(2ⁿ)
// SC: O(2ⁿ × k) k = average length of each subset
void helper(int idx, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums)
{
    ans.push_back(ds);

    for (int i = idx; i < nums.size(); ++i)
    {
        if (i != idx && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        helper(i + 1, ans, ds, nums);
        ds.pop_back();
    }
}

vector<vector<int>> _subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> ds;
    helper(0, ans, ds, nums);
    return ans;
}

int main()
{

    return 0;
}