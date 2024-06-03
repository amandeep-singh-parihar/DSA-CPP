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
    sort(nums.begin(), nums.end());
    int cnt = 0,ls=1;
    for (int i = 0; i < nums.size()-1; ++i)
    {
        if (nums[i] + 1 == nums[i + 1])
        {
            cnt++;
        }
    }
    return cnt+1;
}

int main()
{
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << longestConsecutive(nums);
    return 0;
}