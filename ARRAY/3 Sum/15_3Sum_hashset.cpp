#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> st;
    for (int i = 0; i < nums.size(); ++i)
    {
        set<int> hashset;
        for (int j = i + 1; j < nums.size(); ++j)
        {
            int third = -(nums[i] + nums[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
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