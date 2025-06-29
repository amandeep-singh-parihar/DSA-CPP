// 1. Two Sum
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
// Revision 2

// Brute
// TC O(N^2)
// SC O(1)
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    return res;
}

// Optimal
// TC O(N)
// SC O(1)
vector<int> _twoSum(vector<int> nums, int target)
{
    vector<int> ans;
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); ++i)
    {
        int moreNeeded = target - nums[i];
        if (mpp.find(moreNeeded) != mpp.end())
        {
            ans.push_back(mpp[moreNeeded]);
            ans.push_back(i);
            return ans;
        }
        mpp[nums[i]] = i;
    }
    return {-1, -1};
}

// Optimal
// TC O(N)
// SC O(1)
vector<int> __twoSum(vector<int> nums, int target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); ++i)
    {
        int moreNeeded = target - nums[i];
        if (mpp.find(moreNeeded) != mpp.end())
        {
            return {mpp[moreNeeded], i};
        }
        mpp[nums[i]] = i;
    }
    return {-1, -1};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = __twoSum(nums, target);
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}