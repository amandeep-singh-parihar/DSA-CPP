#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] < 0)
        {
            neg.push_back(nums[i]);
        }
        else
        {
            pos.push_back(nums[i]);
        }
    }
    int i = 0, j = 0;
    nums.clear();
    while (i < pos.size() && j < neg.size())
    {
        nums.push_back(pos[i]);
        nums.push_back(neg[i]);
        i++, j++;
    }
    return nums;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> ans = rearrangeArray(nums);
    cout<<"[";
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i];
        if (i < ans.size() - 1)
        {
            cout << ",";
        }
    }
    cout<<"]";
    return 0;
}