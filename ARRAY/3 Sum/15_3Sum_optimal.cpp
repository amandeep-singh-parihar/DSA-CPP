#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//oral revision 1
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
            {
                ++j;
            }
            else if (sum > 0)
            {
                --k;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                res.push_back(temp);
                ++j, --k;
                while (j < k && nums[j] == nums[j - 1])
                    ++j;
                while (j < k && nums[k] == nums[k + 1])
                    --k;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    for (const auto &triplet : result)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}