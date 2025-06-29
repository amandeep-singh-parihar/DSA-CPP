// 216. Combination Sum III
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC: O(2⁹) = O(512) → effectively constant
// SC: O(k) (depth of recursion stack and temp list ds)

void helper(int i, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums, int k, int n, int sum)
{
    if (sum > n)
        return;
    if (i == nums.size())
    {
        if (sum == n && ds.size() == k)
        {
            ans.push_back(ds);
        }
        return;
    }

    // include
    sum += nums[i];
    ds.push_back(nums[i]);
    helper(i + 1, ans, ds, nums, k, n, sum);
    sum -= nums[i];
    ds.pop_back();

    // exclude
    helper(i + 1, ans, ds, nums, k, n, sum);
}

vector<vector<int>> combinationSum3(int k, int n)
{
    // prepare the vector
    vector<int> nums;
    for (int i = 1; i <= 9; ++i)
    {
        nums.push_back(i);
    }

    vector<vector<int>> ans;
    vector<int> ds;
    helper(0, ans, ds, nums, k, n, 0);
    return ans;
}

int main()
{
    int k = 3;
    int n = 9;
    vector<vector<int>> res = combinationSum3(k, n);
    for (auto it : res)
    {
        for (auto _it : it)
        {
            cout << _it << " ";
        }
        cout << endl;
    }
    return 0;
}