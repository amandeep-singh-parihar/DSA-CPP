#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int longestConsecutive(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int cnt = 0, lastSmallest = INT_MIN, longest = 1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] - 1 == lastSmallest)
        {
            cnt++;
            lastSmallest = nums[i];
        }
        else if (nums[i] != lastSmallest)
        {
            cnt = 1;
            lastSmallest = nums[i];
        }
        longest = max(cnt, longest);
    }
    return longest;
}

int main()
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(nums);
    return 0;
}