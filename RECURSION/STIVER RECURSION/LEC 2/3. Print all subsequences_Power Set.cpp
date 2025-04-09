// 78. Subsets
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void helper(int i, vector<vector<int>> &ans, vector<int> &nums,
            vector<int> &output)
{
    if (i >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // include
    output.push_back(nums[i]);
    helper(i + 1, ans, nums, output);
    output.pop_back();
    // exclude
    helper(i + 1, ans, nums, output);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    helper(0, ans, nums, output);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
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