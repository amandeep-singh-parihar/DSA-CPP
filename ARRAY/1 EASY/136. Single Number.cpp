// 136. Single Number
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        ans ^= nums[i];
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 2, 1};
    cout << singleNumber(nums);
    return 0;
}